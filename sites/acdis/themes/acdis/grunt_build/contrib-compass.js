module.exports = function(grunt) {

	grunt.config('compass', {
		dev: {
			options: {
				config: 'config.rb'
			}
		},
		release: {
			options: {
				config: 'config.rb',
				imageDir: 'release/images',
				cssDir: 'release/styles/css',
				fontsDir: 'release/contrib-fonts',
				outputStyle: 'compressed',
				relativeAssets: true,
				noLineComments: true,
				environment: 'production'
			}
		}
	});

	grunt.loadNpmTasks('grunt-contrib-compass');

};
