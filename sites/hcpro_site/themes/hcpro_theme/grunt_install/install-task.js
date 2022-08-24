module.exports = function(grunt) {

	// This task controls the task sequence that run when 'grunt watch' is run
	grunt.registerTask('install-task', 'Configure the brand theme.', function() {

		var themeName = (function(){
			var infoFile = grunt.file.expand('*.info').toString().split('.');
			return infoFile[0].toString();
		}());

		grunt.themeName = themeName;

		grunt.task.requires('prompt');

		grunt.config('rename', {
			info: {
				files: [
					{src:'' + grunt.themeName + '.info', dest:'' + grunt.config('theme.name') + '.info'}
				]
			},
			themeFolder: {
				files: [
					{src:'../' + grunt.themeName + '', dest:'../' + grunt.config('theme.name')}
				]
			}
		});

		var themeNameClean = grunt.themeName.replace(/_/g, ' ');

		var themeNameNewClean = grunt.config('theme.name').replace(/_/g, ' ');

		var toTitleCase = function(str){
			return str.replace(/\w\S*/g, function(txt){return txt.charAt(0).toUpperCase() + txt.substr(1).toLowerCase();});
		};

		var themeNameLocate = grunt.file.expand('**/*.php', '**/*preprocess.inc', '**/*.info', '**/*.rb', '**/_fonts.scss', '**/*.behaviors.js');

		themeNameLocate.forEach(function(file) {

			grunt.file.write( file, grunt.file.read(file).toString().replace(new RegExp(grunt.themeName, 'g'), grunt.config('theme.name') ) );

			grunt.file.write( file, grunt.file.read(file).toString().replace(new RegExp(toTitleCase(themeNameClean), 'g'), toTitleCase(themeNameNewClean) ) );

		});

		grunt.task.run('rename:themeFolder');

		grunt.task.run('rename:info');

		grunt.log.write('Your sub theme has been moved to the "'.cyan + grunt.config('theme.name').cyan + '" directory. You can move to that directory and run "grunt --force" to compile your site.'.cyan);
	});

	grunt.loadNpmTasks('grunt-prompt');

	grunt.loadNpmTasks('grunt-contrib-rename');

	grunt.loadNpmTasks('grunt-contrib-copy');

};
