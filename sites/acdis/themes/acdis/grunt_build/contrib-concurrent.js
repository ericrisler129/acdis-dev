module.exports = function(grunt) {

  grunt.config('concurrent', {
    optimize: ['jshint', 'bless:dev', 'bless:release'],
    watch: ['bless:dev', 'copy:update', 'copy:updateBrand', 'jshint:gruntfile', 'jshint:scripts']
  });

  grunt.loadNpmTasks('grunt-concurrent');

};
