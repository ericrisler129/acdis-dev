##
## This file is only needed for Compass/Sass integration. If you are not using
## Compass, you may safely ignore or delete this file.
##
## If you'd like to learn more about Sass and Compass, see the sass/README.txt
## file for more information.
##

# Location of the theme's resources.
http_path="/"
http_images_path = "/profiles/hcpro/themes/hcprobt/"
css_dir = "debug/styles/css"
sass_dir = "debug/styles/sass"
images_dir = "debug/images"
javascripts_dir = "scripts"
fonts_dir = "debug/contrib-fonts"

# Require any additional compass plugins installed on your system.
require 'compass-normalize'
require 'rgbapng'
require 'toolkit'
require 'singularitygs'
require 'breakpoint'
require 'sass-globbing'
require 'font-awesome-sass'

# To enable relative paths to assets via compass helper functions. Since Drupal
# themes can be installed in multiple locations, we don't need to worry about
# the absolute path to the theme from the server omega.
relative_assets = true
