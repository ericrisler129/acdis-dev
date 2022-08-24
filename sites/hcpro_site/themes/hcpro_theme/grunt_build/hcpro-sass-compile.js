module.exports = function(grunt) {

	grunt.config('hcproSassCompiler', {
		dev: {
			compile: '<%= compass.dev.options.sassDir %>',
			cleanDirectory: false
		},
		release: {
			compile: '<%= compass.dev.options.sassDir %>',
			cleanDirectory: true
		}
	});

	grunt.registerMultiTask('hcproSassCompiler', 'Sub theme Sass Compiler task.', function() {

		grunt.task.run('copy:sass');

		grunt.task.run('customCopy');

		grunt.task.run('compass:dev');

		if ( !this.data.cleanDirectory ){
			grunt.task.run('clean:dev');
		}
	});

};
