module.exports = function(grunt) {

	grunt.config('prompt', {
		install: {
			options: {
				questions: [
					{
						config: 'theme.name',
						type: 'input',
						message: 'Enter the name of the HCPRO sub theme. (Use _ instead of spaces)'
					}
				]
			}
		},
	});

	grunt.loadNpmTasks('grunt-prompt');

};
