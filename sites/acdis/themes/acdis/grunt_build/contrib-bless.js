/*global module*/
module.exports = function(grunt) {

  // grunt.task.requires('compass:dev');

  grunt.config('bless', {
    dev: {
      options: {
        cleanup: true
      },
      files: {
        'debug/styles/css/screen.css': 'debug/styles/css/screen.css'
      }
    },
    release: {
      options:{
        compress: true,
        cleanup: true
      },
      files:{
        'release/styles/css/screen.css': 'release/styles/css/screen.css'
      }
    }
  });

  grunt.loadNpmTasks('grunt-bless');

};
