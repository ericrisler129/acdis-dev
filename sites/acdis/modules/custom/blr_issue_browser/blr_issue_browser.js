(function ($) {

   Drupal.behaviors.issueBrowser = {
     attach: function () {
       $('.blr-issue-browser').once('ib', function () {
         $volMenu = $(this).find('.menu-volume');
         $issueMenu = $(this).find('.menu-issue');
         $(this).find('.menu-volume:not(".active")').find('.menu-issue').hide();

         $volMenu.each( function() {
           $(this).find('span').click( function() {
             $(this).parent().find('.menu-issue').slideToggle(100);
           })
         })


       })
     }
   };

})(jQuery);
