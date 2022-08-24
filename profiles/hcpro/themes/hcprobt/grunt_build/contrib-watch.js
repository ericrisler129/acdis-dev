/*global module*/
module.exports = function(grunt) {
  // Command: 'grunt watch'
  // Description: Run predefined tasks whenever watched file patterns are added, changed or deleted.
  // URL: https://github.com/gruntjs/grunt-contrib-watch
  grunt.config('watch', {
    // Command: 'grunt watch:gruntfile'
    // Description: Watch for any changes in the javascript files
    gruntfile: {
      // Poll for changes in the grunt file and the scripts folder ('<%= jshint.gruntfile.src %>' is defined in the contrib-jshint.js file (/grunt_build/contrib-watch.js) on line 47 and line 52)
      files: ['<%= jshint.gruntfile.src %>', '<%= jshint.scripts.src %>'],
      // Run the 'grunt jshint:gruntfile' and 'grunt jshint:scripts' tasks
      tasks: ['jshint:gruntfile', 'jshint:scripts']
    },
    // Command: 'grunt watch:compass'
    // Description: Watch for any changes in the sass files
    compass: {
      // Poll for and changes in the sass folder with the '.scss' prefix
      files: 'debug/styles/sass/**/*.scss',
      // Run the 'grunt compass:dev' and 'grunt  compass:dev' tasks
      tasks: ['compass:dev', 'bless:dev']
    }
  });
  // Include the module from the node_modules folder
  grunt.loadNpmTasks('grunt-contrib-watch');
};
