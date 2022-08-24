/*global module*/
module.exports = function(grunt) {
  // Command: 'grunt copy'
  // Description: Copies files and directories to another location
  // URL: https://www.npmjs.org/package/grunt-copy
  grunt.config('copy', {
    main: {
      files: [{
        // Expand allows you to specify whether you want to create the destination path in full (e.g: /path/missing1/missing2), or only create the last directory when its parent exists (/path/existing/missing).
        expand: true,
        // Change working directory to the debug folder (debug)
        cwd: 'debug',
        // Define the folder/files that will be copied
        src: ['contrib-fonts/**/*', 'includes/**/*'],
        // Define the destination for the targeted files
        dest: 'release/'
      }]
    }
  });
  // Include the module from the node_modules folder
  grunt.loadNpmTasks('grunt-contrib-copy');
};
