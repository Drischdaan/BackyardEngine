project 'Engine'
  project_defaults()
  use_precompiled_header()

  configure_dynamic_library()

  postbuildcommands {
    ("{COPY} %{cfg.buildtarget.relpath} \"%{wks.location}/App\"")
  }

  filter 'configurations:Debug'
    includedirs{conan_debug.includedirs}
    libdirs{conan_debug.libdirs}
    links{conan_debug.libs}
    links{conan_debug.system_libs}
    links{conan_debug.frameworks}
    defines{conan_debug.defines}
    bindirs{conan_debug.bindirs}

  filter 'configurations:Release'
    includedirs{conan_release.includedirs}
    libdirs{conan_release.libdirs}
    links{conan_release.libs}
    links{conan_release.system_libs}
    links{conan_release.frameworks}
    defines{conan_release.defines}
    bindirs{conan_release.bindirs}

project 'Editor'
    project_defaults()
    use_precompiled_header()

    debugdir(work_directory)

    includedirs {
      '%{wks.location}/Source/Engine/Public',
    }

    links {
      'Engine',
    }

    filter 'configurations:Debug'
      configure_executable_console()

      includedirs{conan_debug.includedirs}

    filter 'configurations:Release'
      configure_executable_windowed()

      includedirs{conan_release.includedirs}