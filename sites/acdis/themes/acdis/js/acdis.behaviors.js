(function ($) {

  Drupal.behaviors.addNewChapter = {
    attach: function () {
      $('.field-name-local-chapter-menu').once('add-chapter', function () {
		var newChapterHTML = '<li class="leaf"><a href="/chapters/new">+ New Chapter</a></li>';
        $(this).find('.menu .menu li.last').after(newChapterHTML);
      });
	}
  };

  /* Linking pages Merchandise, Sponsorship, submit an activity to CdiWeekMenu */
  Drupal.behaviors.cdiWeekMenu = {
    attach: function () {
      var baseUrl =  Drupal.settings.baseUrl;
      var merchandise = baseUrl+'/cdi-week/merchandise';
      var sponsorship = baseUrl+'/cdi-week/sponsorship';
      var activity = baseUrl+'/cdi-week/submit-an-activity';
      var parts = window.location.pathname.split( '/' );
      var query = parts[parts.length-1].split( '.html' );

	  if($(".cdi-week-pages").length<3){
		$( "#views-exposed-form-cdi-week-home-page .form-item:nth-child(11)" ).append("<a class='cdi-week-pages' href='' id='merchandise_id'>Merchandise</a>");
		$( "#views-exposed-form-cdi-week-home-page .form-item:nth-child(11)" ).append("<a class='cdi-week-pages' href='' id='sponsorship_id'>Sponsorship</a>");
		$( "#views-exposed-form-cdi-week-home-page .form-item:nth-child(5)" ).append("<a class='cdi-week-pages' href='' id='activity_id'>-Submit an Activity</a>");
      }
	  if(query[0] == 'cdi-week' || query[0] == 'merchandise' || query[0] == 'sponsorship' || query[0] == 'submit-an-activity' ){
		$('.style-btn-green').find('a').attr('target','_blank'); // To open the button view in a new window.
	    document.getElementById("merchandise_id").href = merchandise;
	    document.getElementById("sponsorship_id").href = sponsorship;
	    document.getElementById("activity_id").href = activity;
	  }
	  if(query[0] == 'merchandise') {
        $(".bef-select-as-links a").removeClass('active');
		$('#merchandise_id').addClass('active');
	  }
	  else if(query[0] == 'sponsorship') {
		$(".bef-select-as-links a").removeClass('active');
		$('#sponsorship_id').addClass('active');
	  }
	  else if(query[0] == 'submit-an-activity') {
	    $(".bef-select-as-links a").removeClass('active');
		$('#activity_id').addClass('active');
	  }
    }
  };

  // Remove margin from sidebar ad slots if no ad is served
  Drupal.behaviors.adsMargin = {
    attach: function () {
      setTimeout(function() {
        $('.block-ad').each(function() {
          if ($(this).height() <= 0) {
            $(this).css('margin', 0);
          }
        })
      }, 200)
    }
  };

  //Set the h1 title to display for SEO
  Drupal.behaviors.setHeaderTitle = {
	attach: function() {
      let pageTitle = document.title;
      let bodyElement = document.getElementsByTagName("body")[0]
      var injectedH1 = document.createElement('h1');
      injectedH1.innerHTML = pageTitle;
      bodyElement.prepend(injectedH1);
      injectedH1.style.display = 'none';
	}
  };

  //Added as alternative to overcome the active menu issue, caused when updated BEF module to 7.x-3.6
  Drupal.behaviors.viewsBefExposedMenu = {
    attach:function () {
      $('.bef-select-as-links').once(function () {
        $(this).find('a').click(function () {
          var $wrapper = $(this).parents('.bef-select-as-links');

          $selected.attr('selected','selected');
          $wrapper.find('.bef-new-value').val($selected.val());
          $wrapper.find('a').removeClass('active');
          $(this).addClass('active');
         });
      });
    }
  };

  //Update URL on person icon
  Drupal.behaviors.changeUrlValue = {
    attach: function() {
      $(".menu .nav-user .person-icon").attr("href", "#");
    }
  };

  // Apply accordion (collapsible div) for Ask the expert view.
  Drupal.behaviors.collapsableDiv = {
    attach: function() {
      if($(".view-acdis-faq").length > 0){
        $('.views-field-title .field-content').click(function(){
          //$(this).closest('li').find('i').toggleClass('fa-arrow-down');
          var field_content_parent = $(this).parent().next().find('.field-content');
          if(field_content_parent.length){
            field_content_parent.slideToggle('fast');
          }
        });
      }

      if(window.location.hash) {
        var hash = window.location.hash.substring(1);
        $('#' + hash).parent().parent().next().find('.field-content').slideToggle('fast');
        // $('a[href*='+hash+']').closest('.views-field').prev().find('i.fa-arrow-right').toggleClass('fa-arrow-down');
      }
    }
  };

})(jQuery);
