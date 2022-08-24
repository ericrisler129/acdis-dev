<?php

function memberbase_user_profile_page() {
   global $user;
   $profile = memberbase_get_profile();
   $memberbase_id = $profile->memberbase_id;

   // Load from memberbase
    $url = 'https://webservice.blr.com/Membership/AuthenticationService.svc/pox/AuthenticateByUserId?userId='.$memberbase_id;
    $xml = file_get_contents($url);
    libxml_use_internal_errors(true);
    $xml = new SimpleXMLElement($xml);      
    $authStatus = (string) $xml->AuthenticationStatus->StatusCode;

    $xmlUser = [];
    if($authStatus == 'Success')
      foreach(['Email','FirstName','LastName','Institution','UserId','Username'] as $field)
        $xmlUser[$field] = (string) $xml->User->$field;

   $info = memberbase_get_membership_info($xml->User);   
   $sub = [];
   if($info) {
     $roles = user_roles();
     $sub['Membership Tier'] = implode(',',
        array_map(function($r) use ($roles) { return ucwords($roles[$r]); },$info['roles']));
     if(!isset($info['active']) || !$info['active'])
       $sub['Subscription Expiration'] = 'Expired';
     else if($info['expireDate'])
       $sub['Subscription Expiration'] = date('m/d/Y',$info['expireDate']);
   }

   if(isset($_POST['password'])) {
      $client = new SoapClient('https://webservice.blr.com/Membership/UserService.svc?singleWsdl',['trace'=>1]);
      try {
      $json = $client->GetUser(['userId'=>$memberbase_id]);
      $json = $json->GetUserResult;
      $json->Password = $_POST['password'];
      $memberships = new ArrayObject();
      foreach($json->Memberships as $membership) {
       foreach(get_object_vars($membership) as $field=>$value) 
         if(is_null($value))
           unset($membership->$field);
       $memberships->append(new SoapVar($membership,SOAP_ENC_OBJECT,null,null,'Membership'));
     }
      $json->Memberships = $memberships;
        $client->SaveUser(['user'=>$json]);
	drupal_set_message('Password successfully updated.');
      } catch( Exception $e ) {
        watchdog_exception('memberbase',$e,
	'%type: !message in %function (line %line of %file) last request %request',
	['%request'=>$client->__getLastRequest()]);
	drupal_set_message('Your request could not be processed.  Please try again later.','error');
      }
   }

   return theme('mbprofile',['user'=>$xmlUser,'subscription'=>$sub,'profile'=>$profile]);
}

