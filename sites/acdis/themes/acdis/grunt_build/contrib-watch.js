module.exports = function(grunt) {

	grunt.config('watch', {
		hcproSassCompiler: {
			files: 'debug/styles/sass/**/*',
			tasks: ['hcproSassCompiler:dev', 'concurrent:watch']
		},
		baseTheme: {
			files: grunt.basePath + '/debug/styles/sass/**/*',
			tasks: ['hcproSassCompiler:dev', 'concurrent:watch']
		},
		brandTheme: {
			files: grunt.baseBrandPath + '/debug/styles/sass/**/*',
			tasks: ['hcproSassCompiler:dev', 'concurrent:watch']
		}
	});

	grunt.loadNpmTasks('grunt-contrib-watch');

};
