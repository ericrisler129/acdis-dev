module.exports = function(grunt) {

	grunt.config('imageEmbed', {
		release: {
			src: ['release/styles/css/screen.css'],
			dest: 'release/styles/css/screen.css',
			options: {
				deleteAfterEncoding: false,
				maxImageSize: 10000
			}
		}
	});

	grunt.loadNpmTasks('grunt-image-embed');

};