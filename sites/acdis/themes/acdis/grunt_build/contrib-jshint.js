module.exports = function(grunt) {

	grunt.config('jshint', {
		options: {
			curly: true,
			eqeqeq: true,
			immed: true,
			latedef: true,
			newcap: true,
			noarg: true,
			sub: true,
			undef: true,
			unused: false,
			boss: true,
			eqnull: true,
			browser: true,
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
		gruntfile: {
			src: 'Gruntfile.js'
		},
		scripts: {
			src: 'scripts/**/*.js'
		}
	});

	grunt.loadNpmTasks('grunt-contrib-jshint');

};