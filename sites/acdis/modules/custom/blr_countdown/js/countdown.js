(function ($) {

Drupal.behaviors.countdown = {
  attach: function () {
    if (!$.isEmptyObject(Drupal.settings.blr_countdown)) {
      $.each(Drupal.settings.blr_countdown, function() {
        var $countdown = this;
        var blockID = $countdown.blockID;

        $("#block-bean-" + blockID).once('countdown' + blockID, function() {
          var $this = $(this);
          $this.find('.field-name-field-date').before('<div class="countdown-prefix">There are just...</div>')
            .addClass('countdown-timer')
            .after('<div class="countdown-suffix">...left until ' + $countdown.title + '</div>');
        });

        $("#block-bean-" + blockID + " .field-name-field-date").once('countdown-date' + blockID, function() {
          var $this = $(this);
          $this.countdown($countdown.countdownDate, function(event) {
            $this.html(event.strftime('' +
              '<div class="time-section"><span class="time-display">%-D</span><span class="time-label">day%!D</span></div>' +
              '<div class="time-section"><span class="time-display">%-H</span><span class="time-label">hour%!H</span></div>' +
              '<div class="time-section"><span class="time-display">%-M</span><span class="time-label">minute%!M</span></div>' +
              '<div class="time-section"><span class="time-display">%-S</span><span class="time-label">second%!S</span></div>')
            );
          });
        })
      });
    }
  }
};

Drupal.behaviors.countdownShortcode = {
  attach: function () {

    $(".countdown-shortcode").each(function() {
      var $countdown = $(this);

      $countdown.once('countdown', function() {
        var $this = $(this);
        $this.before('<div class="countdown-prefix">There are just...</div>')
          .addClass('countdown-timer')
          .after('<div class="countdown-suffix">...left until ' + $countdown.find('.countdown-title').text() + '</div>');
      });

      $countdown.once('countdown-date', function() {
        var $this = $(this);

        $this.countdown($countdown.find('.field-name-field-date').text(), function(event) {
          $this.html(event.strftime('' +
              '<div class="time-section"><span class="time-display">%-D</span><span class="time-label">day%!D</span></div>' +
              '<div class="time-section"><span class="time-display">%-H</span><span class="time-label">hour%!H</span></div>' +
              '<div class="time-section"><span class="time-display">%-M</span><span class="time-label">minute%!M</span></div>' +
              '<div class="time-section"><span class="time-display">%-S</span><span class="time-label">second%!S</span></div>')
          );
        });
      })
    });
  }
};

})(jQuery);
