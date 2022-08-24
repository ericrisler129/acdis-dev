<?php
$title = variable_get('talk_group_title', 'Talk Group');
?>

<h2 style="color:#0A8282"><?php print $title; ?></h2>

<div style="float: left; padding-right: 20px; padding-bottom: 10px; width: 185px;">
  <img src="/<?php print path_to_theme(); ?>/logo.jpg" />

<div class="button wide" style="margin-top: 5px;width:100%;text-align:center;"><a href="/membership-check?destination=<?php print base_path() . current_path(); ?>" class="button-blue" style="padding:11px 15px;">Sign In</a></div>
<div class="button wide" style="margin-top: 10px;width:100%;text-align:center;"><a href="http://www.hcmarketplace.com/justcoding-com?code=EN327867" class="button-green" target="_blank" style="padding:11px 15px;">Subscribe</a></div>

</div>

<p>Confused about how to code a specific diagnosis or procedure? Wondering how others are improving the coding processes at their facilities? Just want to bounce some ideas off of a peer? Well, you've come to the right place. New and seasoned coding professionals talk regularly via e-mail with their peers on on the <?php print $title; ?>.</p>

<strong>About the <?php print $title; ?></strong></br>
<p>Coding Buzz is a moderated listserv that provides JustCoding members with a forum to network, share ideas, and solve problems. Discussions center on regulatory updates, best practices, suggestions, and other issues related to medical coding.</p>

<p style="font-size: 1.1em; color: #116798; font-weight: bold; font-style: oblique;">Access to the <?php print $title; ?> is included in all Basic, Platinum, and Platinum Plus access levels. Login or Subscribe now!</p>
