<?php

/***
 * Class MemberbaseService
 */
class MemberbaseService {

  const LOG_TAG = 'Memberbase';

  /***
   * @param $service
   * @return mixed
   */
  public static function getClient($service) {
    static $client = [];
    if(!isset($client[$service]))
      $client[$service] = new SoapClient("http://webservice.blr.com/Membership/{$service}Service.svc?singleWsdl",[ 'trace' => 1 ]);

    return $client[$service];
  }

  /***
   * @param $user
   * @return mixed
   */
  private static function prepareUser($user) {
    if(!isset($user->Memberships) || !is_object($user->Memberships))
      $user->Memberships = new stdClass;
    if(isset($user->Memberships->Membership)) {
      if(is_array($user->Memberships->Membership))
        $user->Memberships = $user->Memberships->Membership;
      else
        $user->Memberships = [$user->Memberships->Membership];
    }
    return $user;
  }

  /***
   * @param $username
   * @param $password
   * @return bool
   */
  public static function authenticate($username,$password) {
    $client = self::getClient('Authentication');

    try {
      $result = $client->Authenticate(['username'=>$username,'password'=>$password]);
      return isset($result->AuthenticateResult->User) ? self::prepareUser($result->AuthenticateResult->User) : false;
    } catch( Exception $e ) {
      watchdog('memberbase', $e->getMessage(), null, WATCHDOG_ERROR);
      return false;
    }
  }

  /***
   * @param $username
   * @return bool
   */
  public static function isUsernameAvailable($username) {
    $client = self::getClient('User');

    try {
      $result = $client->IsUsernameAvailable(['username'=>$username]);
      return $result->IsUsernameAvailableResult;
    } catch( Exception $e ) {
      watchdog('memberbase', $e->getMessage(), null, WATCHDOG_ERROR);
      return false;
    }
  }

  /***
   * @param $id
   * @return bool
   */
  public static function getUserById($id) {
    $client = self::getClient('User');

    try {
      $result = $client->GetUser(['userId'=>$id]);
      return isset($result->GetUserResult) ? self::prepareUser($result->GetUserResult) : false;
    } catch( Exception $e ) {
      watchdog('memberbase', $e->getMessage(), null, WATCHDOG_ERROR);
      return false;
    }
  }

  /***
   * @param $username
   * @return bool
   */
  public static function getUserByUsername($username) {
    $client = self::getClient('User');

    try {
      $result = $client->GetUserByUsername(['username'=>$username]);
      return isset($result->GetUserByUsernameResult) ? $result->GetUserByUsernameResult : false;
    } catch( Exception $e ) {
      watchdog('memberbase', $e->getMessage(), null, WATCHDOG_ERROR);
      return false;
    }
  }

  /***
   * @param $username
   * @param $password
   * @param $email
   * @param $firstName
   * @param $lastName
   * @param $company
   * @return \stdClass
   */
  public static function createUser($username,$password,$email,$firstName,$lastName,$company) {
    $user = new stdClass;
    $user->Email = $email;
    $user->FirstName = $firstName;
    $user->Institution = $company;
    $user->LastName = $lastName;
    $user->Memberships = [];
    $user->Password = $password;
    $user->Username = $username;
    return $user;
  }

  /***
   * @param $user
   * @param $applicationId
   * @param $libraryIds
   * @param $type
   * @param $expiration
   * @return \stdClass
   */
  public static function addMembership($user,$applicationId,$libraryIds,$type,$expiration) {
    $newMembership = new stdClass;
    $newMembership->ApplicationId = $applicationId;
    $newMembership->IsActive = 'true';
    $newMembership->Libraries = $libraryIds;
    $newMembership->Role = 'Single';

    if($type == 'trial')
      $newMembership->TrialExpiration = date('Y-m-d',$expiration).'T00:00:00';
    else if($type == 'qf')
      $newMembership->QuickFillExpiration = date('Y-m-d',$expiration).'T00:00:00';

    $user->Memberships[] = $newMembership;
    return $newMembership;
  }

  /***
   * @param $user
   * @return bool
   */
  public static function saveUser(&$user) {
    $client = self::getClient('User');
    $temp = clone $user;
    $memberships = new ArrayObject();
    foreach($user->Memberships as $membership) {
      foreach(get_object_vars($membership) as $field=>$value)
        if(is_null($value))
          unset($membership->$field);

      $memberships->append(new SoapVar($membership,SOAP_ENC_OBJECT,null,null,'Membership'));
    }
    $temp->Memberships = $memberships;

    try {
      $result = $client->SaveUser(['user'=>$temp]);
      if(!isset($user->UserId)) {
        if(!$temp = self::getUserByUsername($user->Username))
          return false;
        $user = $temp;
      }
      return true;
    } catch( Exception $e ) {
      watchdog('memberbase', $e->getMessage(), null, WATCHDOG_ERROR);
      return false;
    }
  }
}
