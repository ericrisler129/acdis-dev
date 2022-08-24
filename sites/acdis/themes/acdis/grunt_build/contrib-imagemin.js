module.exports = function(grunt) {

	grunt.config('imagemin', {
		dynamic: {
			files: [{
				expand: true,
				cwd: 'debug/images/',
				src: ['**/*.png', '**/*.jpg', '**/*.gif'],
				dest: 'release/images/'
			}]
		}
	});

	grunt.loadNpmTasks('grunt-contrib-imagemin');

};