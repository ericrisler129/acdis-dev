module.exports = function(grunt) {

	// This task controls the task sequence that run when 'grunt watch' is run
	grunt.registerTask('update-task', 'Update the client theme.', function() {

		grunt.task.run('copy:update');

	});

	grunt.loadNpmTasks('grunt-contrib-copy');

};