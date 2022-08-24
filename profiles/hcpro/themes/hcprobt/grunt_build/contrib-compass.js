/*global module*/
module.exports = function(grunt) {
  // Command: 'grunt compass'
  // Description: A custom grunt.js task that executes compass compile for you and prints the COMPASS output to grunt.log.write()
  // URL: https://www.npmjs.org/package/grunt-compass
  grunt.config('compass', {
    // Command: 'grunt compass:dev'
    // Description: Compile to the debug folder using the default values defined in the /config.rb file
    dev: {
      options: {
        // Use the default paths from the config.rb
        config: 'config.rb'
      }
    },
    // Command: 'grunt compass:release'
    // Description: Compile to the release folder by overriding the default values defined in the /config.rb to point to /release
    release: {
      options: {
        // Use the default paths from the config.rb as a base
        config: 'config.rb',
        // Updated the imageDir value to point to /release/images
        imageDir: 'release/images',
        // Update the cssDir value to point to /release/styles/css
        cssDir: 'release/styles/css',
        // Update the fontsDir value to point to /release/contrib-fonts
        fontsDir: 'release/contrib-fonts',
        // Compress the compiled code in the release folder
        outputStyle: 'compressed',
        // Set relativeAssests to true to support compass sprites
        relativeAssets: true,
        // Remove line comments
        noLineComments: true,
        // Set to production
        environment: 'production'
      }
    }
  });
  // Include the module from the node_modules folder
  grunt.loadNpmTasks('grunt-contrib-compass');
};
