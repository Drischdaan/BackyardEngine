project 'Editor'
  -- Configure project
  project_defaults()
  use_precompiled_header()

  links {
    'Engine',
    'spdlog',
  }

  includedirs {
    '%{wks.location}/Projects/Engine/Source/Public',
    '%{wks.location}/Projects/ThirdParty/spdlog/include',
  }

  -- Configure kind
  filter 'configurations:Debug'
    configure_executable_console()

  filter 'configurations:Release'
    configure_executable_windowed()