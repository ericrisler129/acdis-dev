/*global module*/
module.exports = function(grunt) {
  // Command: 'grunt jshint'
  // Description: Checks javascript for errors, consoles, formatting problems...
  // URL: https://github.com/gruntjs/grunt-contrib-jshint
  grunt.config('jshint', {
    // For descriptions on the option values refer to this document (http://www.jshint.com/docs/options)
    options: {
      // This option requires you to always put curly braces around blocks in loops and conditionals.
      curly: true,
      // This options prohibits the use of == and != in favor of === and !==.
      eqeqeq: true,
      // This option prohibits the use of immediate function invocations without wrapping them in parentheses.
      immed: true,
      // This option prohibits the use of a variable before it was defined.
      latedef: true,
      // This option requires you to capitalize names of constructor functions
      newcap: true,
      // This option prohibits the use of arguments.caller and arguments.callee.
      noarg: true,
      // This option suppresses warnings about using [] notation when it can be expressed in dot notation: person['name'] vs. person.name.
      sub: true,
      // This option prohibits the use of explicitly undeclared variables
      undef: true,
      // This option warns when you define and never use your variables.
      unused: false,
      // This option suppresses warnings about the use of assignments in cases where comparisons are expected.
      boss: true,
      // This option suppresses warnings about == null comparisons.
      eqnull: true,
      // This option defines globals exposed by modern browsers: all the way from good old document and navigator to the HTML5 FileReader and other new developments in the browser world.
      browser: true,
      // Define globals that will be ignored by jshint within the javascript files
      globals: {
        jQuery: true,
        Snap: true,
        AppScroll: true,
        Modernizr: true,
        Drupal: true,
        settings: true,
        context:true
      }
    },
    // Command: 'grunt jshint:gruntfile'
    // Description: Targets the gruntfile for errors
    gruntfile: {
      src: ['Gruntfile.js', 'grunt_build/**.js']
    },
    // Command: 'grunt jshint:scripts'
    // Description: Targets all the javascript files in the /scripts folder
    scripts:{
      src: 'scripts/**/*.js'
    }
  });
  // Include the module from the node_modules folder
  grunt.loadNpmTasks('grunt-contrib-jshint');
};
