<?php if(!empty($subscription)): ?>

<h3>Subscription Information</h3>

<div class="subscription-details">
<?php foreach($subscription as $label => $info): ?>
<div class="row">
<label><?php echo $label; ?></label><?php echo htmlspecialchars($info); ?>
</div>
<?php endforeach; ?>
</div>

<?php endif; ?>

<?php if(!empty($user)): ?>
<h3>Account Information</h3>

<p>To change any of the information below regarding your account, please call Customer Service at 1-800-650-6787.</p>

<form method="post" id="password-form">
<div class="user-details">

<div class="row">
<label>Customer ID</label><?php echo $user['UserId']; ?>
</div>

<div class="row">
<label>User Name</label><?php echo htmlspecialchars($user['Username']); ?>
</div>

<div class="row">
<label>Email</label><?php echo htmlspecialchars($user['Email']); ?>
</div>

<div class="row">
<label>First Name</label><?php echo htmlspecialchars($profile->first_name); ?>
</div>


<div class="row">
<label>Last Name</label><?php echo htmlspecialchars($profile->last_name); ?>
</div>

<div class="row">
<label>Institution</label><?php echo htmlspecialchars($profile->company); ?>
</div>

<div class="row">
<label>Password</label><input type="password" name="password" />
</div>

<div class="row">
<label>Confirm Password</label><input type="password" name="password2" />
</div>

<button type="submit" class="button button-action">Change Password</button> 

</form>

</div>

<style>
.user-details label, .subscription-details label { display: inline-block; width: 175px; font-weight: normal; }
.user-details > div, .subscription-details > div { padding-bottom: 8px; }
</style>

<?php endif; ?>

<script>
jQuery('#password-form').submit(function() {
  var p1 = jQuery('input[name=password]',this).val();
  var p2 = jQuery('input[name=password2]',this).val();
  if(p1.length < 5 || p2.length < 5) {
    alert('Please complete required fields.  Passwords must be at least 5 characters.');
    return false;
  }
  if(p1 != p2) {
    alert('Passwords do not match.');
    return false;
  }
  return true;
});
</script>