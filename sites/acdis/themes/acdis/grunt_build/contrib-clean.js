module.exports = function(grunt) {

	grunt.config('clean', {
		subUpdate: ['grunt_build', 'grunt_install', 'grunt_update', 'grunt_update_sub', 'config.rb', 'Gemfile', 'Gruntfile.js', 'package.json', '.bowerrc', '.ruby-version'],
		dev: [ 'debug/styles/base-sass' ],
		release: ['release']
	});

	grunt.loadNpmTasks('grunt-contrib-clean');

};