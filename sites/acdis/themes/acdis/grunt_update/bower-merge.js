module.exports = function(grunt) {

	var _ = require('underscore');

	// This task controls the task that combines the base and sub theme bower.json files to support updates from base theme and unique libraries added in the sub theme
	grunt.registerTask('bower-merge', 'Update the client theme.', function() {
		var subThemeBower = JSON.parse(grunt.file.read('bower.json').toString());
		var baseThemeBower = JSON.parse(grunt.file.read(grunt.basePath + '/bower.json').toString());
		var deps = _.extend(baseThemeBower.devDependencies, subThemeBower.devDependencies);
		subThemeBower.devDependencies = deps;
		grunt.file.write('bower.json', JSON.stringify(subThemeBower));

	});

	grunt.loadNpmTasks('grunt-contrib-copy');

};