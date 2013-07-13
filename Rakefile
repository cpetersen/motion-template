# -*- coding: utf-8 -*-
$:.unshift("/Library/RubyMotion/lib")
require 'motion/project/template/ios'

require 'rubygems'
require 'yaml'
require 'motion-pixate'
require 'motion-testflight'

config = YAML.load_file("config.yml")

Motion::Project::App.setup do |app|
  # Use `rake config' to see complete project settings.
  app.name = 'motion-template'

  app.pixate.user = config['pixate_user'] if config['pixate_user']
  app.pixate.key  = config['pixate_key'] if config['pixate_key']
  app.pixate.framework = 'vendor/PXEngine.framework'

  app.development do
    app.testflight do
      app.testflight.sdk = 'vendor/TestFlightSDK1.2.6'
      app.testflight.api_token = config['development']['testflight_api_token'] if config['development']['testflight_api_token']
      app.testflight.team_token = config['development']['testflight_team_token'] if config['development']['testflight_team_token']
      app.testflight.notify = true # default is false
      app.testflight.identify_testers = true # default is false
    end
    app.provisioning_profile = config['development']['provisioning_profile']
  end


  app.release do
    app.provisioning_profile = config['release']['provisioning_profile']
  end
end
