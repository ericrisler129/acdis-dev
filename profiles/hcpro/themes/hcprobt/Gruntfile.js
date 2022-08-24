/*global module*/
module.exports = function(grunt) {
    'use strict';
    /**
     * Isolate the unique client theme name to use in file paths
     */
    var themeName = function(){
        // Isolate the current theme by grabbing the value of the .info file name and splitting the string on the '.'
        var infoFile = grunt.file.expand('*.info').toString().split('.');
        // Return the first value (the theme name) from the resulting infoFile array
        return infoFile[0];
    };
    // Store the current theme name on the grunt object for global accessibility
    grunt.themeName = themeName;
    // Read the package.json file to get the 'Name', 'Description', 'version' and the 'devDependencies' for this theme
    grunt.initConfig({
        // Store the information onto the pkg method in the initConfig
        pkg: grunt.file.readJSON('package.json')
    });
    // Load all the grunt tasks that are in the grunt_build folder
    grunt.loadTasks('grunt_build');
    // Define the sequential tasks that will be run on the 'grunt' command
    // This command compiles the site to the release version
    grunt.registerTask('default', [
        // Run the clean task to remove the existing (if any) /release folder
        'clean',
        // Copy the contrib-fonts over to a new /release folder
        'copy',
        // Copy and minify the images from the /debug folder to the /release folder
        'imagemin',
        // Copy and minify svg from the /debug folder to the /release folder
        'svgmin',
        // Compile a new version of the CSS files to /debug/styles/css and a new version of the CSS files to /release/styles/css
        'compass',
        // Check Gruntfile.js and javascript files in /grunt_build, and /scripts folders
        'jshint',
        // Encode images directly into the css in the /release folder
        'imageEmbed',
        // Make sure the compiled styles in /debug/styles/css are compliant with the IE 4095 bug
        'bless:dev',
        // Make sure the compiled styles in /release/styles/css are compliant with the IE 4095 bug
        'bless:release'
    ]);
};
