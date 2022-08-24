/*global module*/
module.exports = function(grunt) {
  // Command: 'grunt svgmin'
  // Description: Minifies svg file
  // URL: https://github.com/sindresorhus/grunt-svgmin
  grunt.config('svgmin', {
    options: {
      plugins: [{
        // Don't remove the viewbox atribute from the SVG
        removeViewBox: false
      }]
    },
    // Command: 'grunt svgmin:release'
    // Minifies the SVG files and copies them to /release/images
    release: {
      files: [{
        // Expand allows you to specify whether you want to create the destination path in full (e.g: /path/missing1/missing2), or only create the last directory when its parent exists (/path/existing/missing).
        expand: true,
        // Change working directory to the debug folder (debug/images)
        cwd: 'debug/images',
        // Define which image formats will be minified (all .svg)
        src: ['**/*.svg'],
        // Define the destination for the minified images
        dest: 'release/images',
        // Add this extension to the files
        ext: '.svg'
      }]
    }
  });
  // Include the module from the node_modules folder
  grunt.loadNpmTasks('grunt-svgmin');
};
