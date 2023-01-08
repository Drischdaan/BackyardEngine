workspace 'BackyardEngine'
  location './../../../'

  configurations {
    'Debug',
    'Release',
  }

  platforms {
    'Windows',
    'Linux',
  }

  filter { 'platforms:Windows' }
    system 'Windows'
    architecture 'x64'

  filter { 'platforms:Linux' }
    system 'Linux'
    architecture 'x64'