module.exports = function(grunt) {

	grunt.config('copy', {

		// Base Update tasks
		update: {
			files: [
				{
					expand: true,
					cwd: grunt.basePath + '/debug',
					src: ['images/contrib-structure/**/*', 'contrib-fonts/**/*', 'includes/**/*'],
					dest: 'debug'
				}
			]
		},
		// Base Build tasks
		sass: {
			files: [
				{
					expand: true,
					cwd: grunt.basePath + '/debug/styles/sass',
					src: ['**/*.scss'],
					dest: 'debug/styles/base-sass'
				}
			]
		},
		// Brand Update tasks
		updateBrand: {
			files: [
				{
					expand: true,
					cwd: grunt.baseTemplatePath + '/debug',
					src: ['images/contrib-structure/**/*', 'contrib-fonts/**/*', 'includes/**/*'],
					dest: 'debug'
				}
			]
		},
		// Brand Build tasks
		sassBrand: {
			files: [
				{
					expand: true,
					cwd: grunt.baseTemplatePath + '/debug/styles/sass',
					src: ['**/*.scss'],
					dest: 'debug/styles/base-sass'
				}
			]
		},
		// Sub update tasks
		subUpdate: {
			files: [
				{
					expand: true,
					cwd: '../../../hcpro_site/themes/hcpro_theme',
					src: ['grunt_build/**/*', 'grunt_install/**/*', 'grunt_update/**/*', 'grunt_update_sub/**/*', 'config.rb', 'Gemfile', 'Gruntfile.js', 'package.json', '.bowerrc', '.ruby-version'],
					dest: ''
				}
			]
		},
		release: {
			files: [
				{
					expand: true,
					cwd: 'debug',
					src: ['fonts/**/*', 'contrib-fonts/**/*', 'includes/**/*'],
					dest: 'release/'
				}
			]
		}
	});

	grunt.loadNpmTasks('grunt-contrib-copy');

};
