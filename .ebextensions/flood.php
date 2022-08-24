<?php

function flood_control() {

   // We define two flood limits

   // More than 12 requests in 3 seconds (4 requests/sec) - unlocks in 10 seconds
   // More than 90 requests in 60 seconds (1.5 requests/sec) - unlocks in 30 seconds

   $limits = [
      'a'=>[12,3,10],
      'b'=>[90,60,30]
   ];
   
   $ip = $_SERVER['REMOTE_ADDR'];
   if(isset($_SERVER['HTTP_X_FORWARDED_FOR'])) {
   		$ip = $_SERVER['HTTP_X_FORWARDED_FOR'];
	   if($i = strpos($ip,';')) $ip = substr($ip,0,$i);
   }
   
   $file = '/tmp/flood/'.$ip;

   $ts = filemtime($file);
   if(!$ts) @touch($file);
   $now = time();
   
   if(!$fp = @fopen($file,'r+')) // Can't open file so don't continue
    return;

    // See if we can lock file
   $flock = @flock($fp, LOCK_EX);
      
   if(!$ts) {
      $data = [];
      $e = 0;
   } else {
      $data = json_decode(fread($fp,512),true);
      if(!$data) $data = [];
      $e = $now - $ts; // Time since last time we touched the file 
   }

   // Update the counters and check for flood
   $flood = false;
   
   foreach($limits as $code => $values) {
     if(!isset($data[$code]) || sizeof($data[$code]) != 2) {
       $data[$code] = [1,0]; // First number is the counter, second is the unlock timestamp
       continue;
     }
     
     if($data[$code][1] > 0) {
       if($data[$code][1] < $now)
          $data[$code] = [1,0];
       else
	  $flood = true;
       continue;
     }
     
     // Adjust the counter by adding 1 and substracting rate * e
     $data[$code][0] = max(1, $data[$code][0] + 1 - $e * $values[0] / $values[1]);

     // Did we trigger flood status?
     if($data[$code][0] >= $values[0]) {
      $data[$code][1] = $now + $values[2];     		
      @file_put_contents('/var/log/flood.log',
        date('c') . ' ' . $code . ' ' . $ip . "\n", FILE_APPEND);
     }
   }

   fseek($fp,0);
   $data = json_encode($data);
   fwrite($fp,$data);
   ftruncate($fp,strlen($data));
   
   if($flock) @flock($fp, LOCK_UN);
   fclose($fp);

   if($flood) {
     header('HTTP/1.1 429 Too Many Requests');
     die('Too many requests have been received from your IP address recently.  Please wait a few seconds and try again.');
   }
}

flood_control();
?>