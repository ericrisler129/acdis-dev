(function(){
  var ad = {
    overlay: document.getElementById("page_overlay"),
    wrapper: document.getElementById("ad_wrapper"),
    body: document.getElementById("ad_main"),
    header: document.getElementById("ad_header"),
    links: document.getElementById("ad_links"),
    closeButton: document.getElementById("ad_close"),
    logoPath: "/dfp/logo.png",
    lifespan: 10,
    openDelay: 0,
    lifeTimer: null,
    openTimer: null,
    open: function() {
      var _this = this;
      clearTimeout(this.openTimer);
      this.overlay.style.display = "block";
      this.lifeTimer = setTimeout(function() {_this.close()}, _this.lifespan * 1000);
    },
    close: function() {
      clearTimeout(this.lifeTimer);
      this.overlay.parentNode.removeChild(this.overlay);
    },
    trigger: function() {
      var _this = this;
      this.openTimer = setTimeout(function() {_this.open()}, _this.openDelay * 1000);
      this.closeButton.onclick = function() {_this.close()};
    }
  };

  ad.overlay.setAttribute("style", "display:none; position:fixed; top: 0; bottom: 0; left: 0; right: 0; z-index: 2147483647; background-color: #cccccc;");
  ad.wrapper.setAttribute("style", "text-align: center; padding-top: 25px;");
  ad.body.setAttribute("style", "display: inline-block; position: relative; background-color:#ffffff; padding: 10px;");
  ad.header.setAttribute("style", "background-color: #ffffff; height: 100px;");
  ad.links.setAttribute("style", "padding: 0 0 10px;");
  ad.closeButton.setAttribute("style", "position: absolute; right: 10px;");
  ad.header.innerHTML = "<img src='" + ad.logoPath + "' style='max-width: 450px; padding: 20px;' />";

  ad.trigger();
}());
