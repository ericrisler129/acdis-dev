/*global module*/
module.exports = function(grunt) {
  // Command: 'grunt clean'
  // Description: Removes previously generated files and directories.
  // URL: https://www.npmjs.org/package/grunt-clean
  grunt.config('clean', {
    // Command: 'grunt clean:release'
    // Description: Remove the release folder before compass creates a new one, this is to prevent the accumulation of unneeded files in the release folder. Also clean out all '.DS_STORE'
    release: ['release', '**/*/.DS_STORE']
  });
  // Include the module from the node_modules folder
  grunt.loadNpmTasks('grunt-contrib-clean');
};
