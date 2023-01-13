project 'Engine'
  -- Configure project
  project_defaults()
  use_precompiled_header()

  -- Configure kind
  configure_static_library()

  defines {
    '_BACKYARD_ENGINE_COMPILE',
  }

  includedirs {
    '%{wks.location}/Projects/ThirdParty/spdlog/include',
  }

  links {
    'spdlog',
  }