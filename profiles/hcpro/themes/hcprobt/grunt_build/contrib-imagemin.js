/*global module*/
module.exports = function(grunt) {
  // Command: 'grunt imagemin'
  // Description: Minifies images
  // URL: https://github.com/gruntjs/grunt-contrib-imagemin
  grunt.config('imagemin', {
    dynamic: {
      files: [{
        // Expand allows you to specify whether you want to create the destination path in full (e.g: /path/missing1/missing2), or only create the last directory when its parent exists (/path/existing/missing).
        expand: true,
        // Change working directory to the debug folder (debug/images)
        cwd: 'debug/images/',
        // Define which image formats will be minified
        src: ['**/*.png', '**/*.jpg', '**/*.gif'],
        // Define the destination for the minified images
        dest: 'release/images/'
      }]
    }
  });
  // Include the module from the node_modules folder
  grunt.loadNpmTasks('grunt-contrib-imagemin');
};
