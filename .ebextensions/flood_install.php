<?php 

$entryScripts = ['index.php'];

if(!file_exists('/tmp/flood')) {
	mkdir('/tmp/flood');
	chmod('/tmp/flood', 0777);
}

if(!file_exists('/var/log/flood.log')) {
	touch('/var/log/flood.log');
	chmod('/var/log/flood.log', 0777);
}

if(!$text = file_get_contents('.ebextensions/flood.php'))
	return;

foreach($entryScripts as $script) {
	if($data = file_get_contents($script)) {
		$data = $text .  "\n" . $data;
		file_put_contents($script, $data);
	}
}

if(!file_exists('/etc/cron.d/flood'))
	file_put_contents('/etc/cron.d/flood', "10 */3 * * *     root find /tmp/flood -mtime +1 -exec rm {} \;");
?>