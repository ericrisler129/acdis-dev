module.exports = function(grunt) {

	// This task controls the task sequence that run when 'grunt watch' is run
	grunt.registerTask('build-task', 'Configure the client theme.', function() {
		grunt.task.run('clean:release');
		grunt.task.run('hcproSassCompiler:release');
		grunt.task.run('imagemin');
		grunt.task.run('copy:release');
		grunt.task.run('compass:release');
		grunt.task.run('clean:dev');
		grunt.task.run('concurrent:optimize');
		grunt.task.run('imageEmbed');
	});
};
