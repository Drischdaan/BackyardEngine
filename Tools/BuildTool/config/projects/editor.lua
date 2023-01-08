project 'Editor'
  -- Configure project
  project_defaults()
  use_precompiled_header()

  -- Configure kind
  filter 'configurations:Debug'
    configure_executable_console()

  filter 'configurations:Release'
    configure_executable_windowed()