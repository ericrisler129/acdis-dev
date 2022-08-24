/*global module*/
module.exports = function(grunt) {
  // Command: 'grunt bless'
  // Description: A grunt module for Blessing your CSS files so they will work in Internet Explorer. This module is used to fix the IE 4095 bug (http://blogs.msdn.com/b/ieinternals/archive/2011/05/14/10164546.aspx)
  // URL: https://www.npmjs.org/package/grunt-bless
  grunt.config('bless', {
    // Command: 'grunt bless:dev'
    // Description: Target the debug folder to make adjustments for the 4095 bug
    dev: {
      options: {
        // Remove unneeded (old) bless files
        cleanup: true
      },
      files: {
        // Rewrite the compiled CSS to support the bless in the debug folder
        'debug/styles/css/screen.css': 'debug/styles/css/screen.css'
      }
    },
    // Command: 'grunt bless:release'
    // Description: Target the release folder to make adjustments for the 4095 bug
    release: {
      options:{
        // Compress the
        compress: true,
        // Remove unneeded (old) bless files
        cleanup: true
      },
      files:{
        // Rewrite the compiled CSS to support the bless in the release folder
        'release/styles/css/screen.css': 'release/styles/css/screen.css'
      }
    }
  });
  // Include the module from the node_modules folder
  grunt.loadNpmTasks('grunt-bless');
};
