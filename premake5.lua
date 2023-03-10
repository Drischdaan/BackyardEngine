include './Tools/premake/utility.lua'

workspace 'BackyardEngine'

  configurations {
    'Debug',
    'Release',
  }

  platforms {
    'Windows',
  }

  filter { 'platforms:Windows' }
    system 'Windows'
    architecture 'x64'

  filter { 'platforms:Linux' }
    system 'Linux'
    architecture 'x64'

include './Tools/premake/projects.lua'