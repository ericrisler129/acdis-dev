module.exports = function(grunt) {

	// This task controls the task sequence that run when 'grunt watch' is run
	grunt.registerTask('update-sub-task', 'Update the client theme from the sub theme template.', function() {

		grunt.task.run('clean:subUpdate');

		grunt.task.run('copy:subUpdate');

	});

	grunt.loadNpmTasks('grunt-contrib-copy');

};