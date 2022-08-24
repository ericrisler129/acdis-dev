module.exports = function(grunt) {
	'use strict';

	// This task is run from the hcproSassCompiler custom task
	// Custom copy task the moves the sass file from the client sass folder into base-sass
	grunt.registerTask('themeName', 'Sub theme custom copy task.', function() {

		// isolate the unique client theme name to use in file paths
		var themeName = (function(){
			var infoFile = grunt.file.expand('*.info').toString().split('.');
			return infoFile[0];
		}());

		grunt.themeName = themeName.toString();

	});

};
