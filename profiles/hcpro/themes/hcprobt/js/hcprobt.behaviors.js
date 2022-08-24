(function ($) {

  Drupal.theme.prototype.fileDownloadButton = function (target) {
    var file = $(target).find('.file');
    var href = file.find('a').attr('href');
    $(file).after('<div class="button"><a download="' + href + '" href="' + href + '">Download</a></div>');
  };

	// Fix bug in MEFIBS -> BEF links do not get click event in additional blocks
	// Replicate BEF functionality for MEFIBS
  Drupal.behaviors.better_exposed_filters_select_as_links_resources = {
    attach: function (context) {

      $('.block-filter-resource-types').find('.bef-select-as-links', context).once(function () {
        // Attach selection toggle and form submit on click to each link.
        $(this).find('a').click(function (event) {
          var $wrapper = $(this).parents('.bef-select-as-links');
          var $options = $wrapper.find('select option');
          // We have to prevent the page load triggered by the links.
          event.preventDefault();
          event.stopPropagation();
          // Un select old select value.
          $wrapper.find('select option').removeAttr('selected');

          // Set the corresponding option inside the select element as selected.
          var link_text = $(this).text();
          var $selected = $options.filter(function () {
            return $(this).text() === link_text;
          });
          $selected.attr('selected', 'selected');
          $wrapper.find('.bef-new-value').val($selected.val());
          $wrapper.find('a').removeClass('active');
          $(this).addClass('active');
          // Submit the form.
          $wrapper.parents('form').find('.views-submit-button *[type=submit]').click();
        });
      });
    }
  };

  Drupal.behaviors.addDownloadButton = {
    attach: function () {
      $('.styled-download').once('button-added', function () {
        //Drupal.theme('fileDownloadButton', '.node--resource.article-detail');
        Drupal.theme('fileDownloadButton', $(this));
      });
    }
  };

  Drupal.behaviors.mobileMenu = {
    attach: function () {
      var $menu = $('.hamburger+.menu');
      $menu.once('menu', function() {
        $menu.find('.expanded > a').click( function(e) {
          if ($('.hamburger:visible').length > 0) {
            e.preventDefault();
            $menu.find('.active').removeClass('active').find('.menu').slideToggle(200);
            $(this).parent().addClass('active').find('.menu').slideToggle(200);
          }
        })
      });
    }
  }

})(jQuery);
