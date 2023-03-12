project 'Engine'
  project_defaults()
  use_precompiled_header()

  configure_dynamic_library()

  postbuildcommands {
    ("{COPY} %{cfg.buildtarget.relpath} \"%{wks.location}/App\"")
  }

project 'Editor'
  project_defaults()
  use_precompiled_header()

  debugdir(work_directory)

  includedirs {
    '%{wks.location}/Projects/Engine/src',
  }

  links {
    'Engine',
  }

  filter 'configurations:Debug'
    configure_executable_console()

  filter 'configurations:Release'
    configure_executable_windowed()