project 'Editor'
  -- Configure project
  project_defaults()
  use_precompiled_header()

  links {
    'Engine'
  }

  includedirs {
    '%{wks.location}/Projects/Engine/Source/Public',
  }

  -- Configure kind
  filter 'configurations:Debug'
    configure_executable_console()

  filter 'configurations:Release'
    configure_executable_windowed()