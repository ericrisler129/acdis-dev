/*global module*/
module.exports = function(grunt) {
  // Command: 'grunt imageEmbed'
  // Description: A grunt task for converting images inside a stylesheet to base64-encoded data URI strings.
  // URL: https://github.com/ehynds/grunt-image-embed
  grunt.config('imageEmbed', {
    // Command: 'grunt imageEmbed:release'
    // Description: Rewrite the compiled screen.css file while checking to see if any image can the embedded in the css
    release: {
      // Define which file is going to be combed through
      src: ['release/styles/css/screen.css'],
      // Define the destination for the combed file after rewrite
      dest: 'release/styles/css/screen.css',
      options: {
        // Set this to true to delete images after they've been encoded. (DO NOT SET TO TRUE)
        deleteAfterEncoding: false,
        // Set the max image size (any image that is smaller will be embedded in the css)
        maxImageSize: 10000
      }
    }
  });
  // Include the module from the node_modules folder
  grunt.loadNpmTasks('grunt-image-embed');
};
