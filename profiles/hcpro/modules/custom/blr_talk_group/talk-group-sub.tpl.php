<?php
$title = variable_get('talk_group_title', 'Talk Group');
$list = variable_get('talk_group_list', '');
?>

<h2 style="color:#0A8282">You are currently subscribed to the <?php print $title; ?></h2>

<div style="float: left; padding-right: 20px; padding-bottom: 10px; width: 185px;">
  <img src="/<?php print path_to_theme(); ?>/logo.jpg" />

<div class="button wide" style="margin-top: 5px;width:100%;text-align:center;"><a href="http://list.hcpro.com/read/?forum=<?php print $list; ?>" class="button-blue" target="_blank" style="padding:11px 15px;">Visit the Archives</a></div>
<div class="button wide" style="margin-top: 10px;width:100%;text-align:center;"><a href="/talk-group/unsubscribe" style="padding:11px 15px;" class="button-green">Unsubscribe</a></div>

</div>

<p>Confused about how to code a specific diagnosis or procedure? Wondering how others are improving the coding processes at their facilities? Just want to bounce some ideas off of a peer? Well, you've come to the right place. New and seasoned coding professionals talk regularly via e-mail with their peers on on the <?php print $title; ?>.</p>

<strong>About the <?php print $title; ?></strong></br>
<p>Coding Buzz is a moderated listserv that provides JustCoding members with a forum to network, share ideas, and solve problems. Discussions center on regulatory updates, best practices, suggestions, and other issues related to medical coding.</p>

<p><span style="font-weight:bold">Digest feature:</span> Coding Buzz Talk has a digest feature. Subscribers who want to receive each day's postings in a single message can do so. Simply send a blank email to <a href="mailto:<?php print $list; ?>-digest@list.hcpro.com"><?php print $list; ?>-digest@list.hcpro.com</a> and we'll update your subscription to the digest version rather than the regular version of Coding Buzz Talk.</p>

<p><span style="font-weight:bold">How it works:</span> Members can post a message or question to the list 24 hours a day. Address messages that you want to send to the entire list to <a href="mailto:<?php print $list; ?>@list.hcpro.com"><?php print $list; ?>@list.hcpro.com</a>. The list moderator reviews each message during normal working hours and either addresses it directly or broadcasts the message to list members for their comments.</p>
