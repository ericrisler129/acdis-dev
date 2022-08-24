/*global module*/
module.exports = function(grunt) {
	'use strict';

	// isolate the unique client theme name to use in file paths
	var themeName = function(){
		var infoFile = grunt.file.expand('*.info').toString().split('.');
		return infoFile[0];
	};

	grunt.themeName = themeName;

	grunt.basePath = '../../../../profiles/hcpro/themes/hcprobt';
	grunt.baseTemplatePath = '../hcpro_theme';

	grunt.initConfig({
		pkg: grunt.file.readJSON('package.json')
	});

	grunt.loadTasks('grunt_install');
	grunt.loadTasks('grunt_update');
	grunt.loadTasks('grunt_update_sub');
	grunt.loadTasks('grunt_build');
	//grunt.loadTasks('grunt_scripts');

	grunt.registerTask('iub', [
		'prompt',
		'update-task',
		'build-task',
		'install-task'
	]);

	grunt.registerTask('install-site', [
		'prompt',
		'update-task',
		'install-task'
	]);

	grunt.registerTask('update-site', [
		'update-task',
		'update-sub-task',
		'build-task'
	]);

	grunt.registerTask('default', [
		'build-task'
	]);
};

