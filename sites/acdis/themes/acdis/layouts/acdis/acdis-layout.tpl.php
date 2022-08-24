<?php $theme_path = hcprobt_get_path(); ?>
<?php print render($page['leaderboard_top']); ?>
<div<?php print $attributes; ?>>
  <header class="l-header" role="banner">
    <div class="l-site-width">
      <?php if (user_is_logged_in()): ?>
        <div class="welcome-message element-invisible">
          Welcome, <a id="uname-gtm" href="/edit-profile"><?php print ucfirst($GLOBALS['user']->name); ?></a>
          Account:
          <?php
          foreach($GLOBALS['user']->roles as $role) {
            if ($role != 'authenticated user') {
              print "<a id='utype-gtm' href='/edit-profile'>{$role}</a>";
            }
          }
          ?>
        </div>
      <?php endif; ?>
      <div class="l-branding">
        <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
        <?php endif; ?>
      </div>
      <?php print render($page['header']); ?>
    </div>
  </header>

  <div class="l-navigation">
    <div class="l-site-width">
      <?php print render($page['navigation']); ?>
    </div>
  </div>

  <div class="l-section-header">
    <?php if (isset($section_title)): ?>
      <div class="section-title-wrapper section-title-<?php print str_replace(' ', '_', strtolower($section_title)); ?>">
        <?php if (isset($section_subtitle)): ?>
          <span class="section-subtitle"><span class="section-icon-inner"><?php print htmlspecialchars_decode($section_subtitle); ?></span></span>
        <?php endif; ?>
        <span class="section-title"><?php print $section_title; ?></span>
        <span class="section-breadcrumbs"><?php print $breadcrumb; ?></span>
      </div>
    <?php endif; ?>
  </div>

  <div class="l-main">
    <div class="l-masthead">
      <?php print render($page['masthead']); ?>
    </div>
    <?php print $messages; ?>
    <?php print render($tabs); ?>
    <?php if ($action_links): ?>
      <ul class="action-links"><?php print render($action_links); ?></ul>
    <?php endif; ?>
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
      <div class="main-title-wrapper">
        <?php if ($page['faux_title_icon']): ?>
          <span class="title-icon"><i class="<?php print $page['faux_title_icon']; ?>"></i></span>
        <?php endif; ?>
        <h1 class="main-h1"><?php print $title; ?></h1>
      </div>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php if ($page['faux_title']): ?>
      <div class="faux-title-wrapper">
        <span class="faux-title-icon"><i class="<?php print $page['faux_title_icon']; ?>"></i></span>
        <span class="faux-title"><?php print $page['faux_title']; ?></span>
      </div>
    <?php endif; ?>

    <div class="clearfix"></div>

    <div class="l-content" role="main">
      <a id="main-content"></a>
      <?php print render($page['content']); ?>
    </div>

    <?php print render($page['sidebar_first']); ?>
    <?php print render($page['sidebar_second']); ?>
    <div class="l-content-bottom">
      <?php print render($page['content_bottom']); ?>
    </div>
  </div>

  <footer class="l-footer" role="contentinfo">
    <div class="l-site-width">
      <!--div class="hcpro-logo"><img src="/<?php //print $theme_path; ?>/images/acdis.png" /></div-->
      <?php print render($page['footer']); ?>
      <?php if (theme_get_setting('hcpro_copyright')): ?>
        <div class="copyright"><?php print theme_get_setting('hcpro_copyright'); ?></div>
      <?php endif; ?>
    </div>
  </footer>
</div>
