module.exports = function(grunt) {
	'use strict';

	grunt.config('customCopy', {
		brandTheme:{
			files: [
				{
					expand: true,
					cwd: '../hcpro_theme/debug/styles/sass',
					src: ['**/*.scss'],
					dest: 'debug/styles/base-sass'
				}
			]
		},
		subTheme:{
			files: [
				{

					expand: true,
					cwd: 'debug/styles/sass',
					src: ['**/*.scss'],
					dest: 'debug/styles/base-sass'
				}
			]
		}
	});

	// This task is run from the hcproSassCompiler custom task
	// Custom copy task the moves the sass file from the client sass folder into base-sass
	grunt.registerMultiTask('customCopy', 'Sub theme custom copy task.', function() {

		var kindOf = grunt.util.kindOf;

		var detectDestType = function(dest) {
			if (grunt.util._.endsWith(dest, '/')) {
				return 'directory';
			} else {
				return 'file';
			}
		};

		var baseSassPathUpdate = function(){
			var basePartial = grunt.file.expand('config.rb');
			var baseParitalRead = grunt.file.read(basePartial).toString().replace(/hcprobt/g, grunt.themeName);
			grunt.file.write('config.rb', baseParitalRead);
		};

		var unixifyPath = function(filepath) {
			if (process.platform === 'win32') {
				return filepath.replace(/\\/g, '/');
			} else {
				return filepath;
			}
		};

		var options = this.options({
			processContent: false,
			processContentExclude: []
		});

		var copyOptions = {
			process: options.processContent,
			noProcess: options.processContentExclude
		};

		grunt.verbose.writeflags(options, 'Options');

		var dest;
		var isExpandedPair;
		var tally = {
			dirs: 0,
			files: 0
		};

		this.files.forEach(function(filePair) {
			isExpandedPair = filePair.orig.expand || false;

			filePair.src.forEach(function(src) {
				if (detectDestType(filePair.dest) === 'directory') {
					dest = (isExpandedPair) ? filePair.dest : unixifyPath(path.join(filePair.dest, src));
				} else {
					dest = filePair.dest;

					var combineArray = [];
					var sourcePath = filePair.src.toString();
					var destinationPath = filePair.dest.toString();

					var prominentFind = function(file){
						if ( file.search('Prominent') > 0 ){
							return true;
						} else {
							return false;
						}
					};

					// check to see if the file exists in the base-sass folder
					if ( grunt.file.exists(dest) && !prominentFind(grunt.file.read(src) )){

						combineArray.push(destinationPath);
						combineArray.push(sourcePath);

						var valid = combineArray.filter(function(filepath) {

							// Warn on and remove invalid source files (if nonull was set).
							if (!grunt.file.exists(filepath)) {
								grunt.log.warn('Source file "' + filepath + '" not found.');
								return false;
							} else {
								return true;
							}
						});

						var max = valid
						.map(grunt.file.read)
						.join(grunt.util.normalizelf(grunt.util.linefeed));

						if (max.length < 1) {
							grunt.log.warn('Destination not written because minified CSS was empty.');
						} else {
							grunt.file.write(filePair.dest, max);
							grunt.log.writeln('File ' + filePair.dest + ' created.');
						}

					} else {
						// else copy the file into base-sass folder
						if (grunt.file.isDir(src)) {
							grunt.verbose.writeln('Creating ' + dest.cyan);
							grunt.file.mkdir(dest);
							tally.dirs++;
						} else {
							grunt.verbose.writeln('Copying ' + src.cyan + ' -> ' + dest.cyan);
							grunt.file.copy(src, dest, copyOptions);
							tally.files++;
						}
					}
				}
			});
		});

		baseSassPathUpdate();

		if (tally.dirs) {
			grunt.log.write('Created ' + tally.dirs.toString().cyan + ' directories');
		}

		if (tally.files) {
			grunt.log.write((tally.dirs ? ', copied ' : 'Copied ') + tally.files.toString().cyan + ' files');
		}

		grunt.log.writeln();
	});

};
