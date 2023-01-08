function resetFilter()
  filter {}
end

function project_defaults()
  resetFilter()
  location (defaultProjectLocation)

  language 'c++'
  cppdialect 'c++20'

  targetdir (buildDirectory)
  objdir (objectBuildDirectory)

  files {
    '%{prj.location}/Source/**/*.h',
    '%{prj.location}/Source/**/*.hpp',
    '%{prj.location}/Source/**/*.cpp',
  }

  includedirs {
    '%{prj.location}/Source/',
    '%{prj.location}/Source/Public',
    '%{prj.location}/Source/Private',
  }

  filter 'system:Windows'
    systemversion 'latest'

    defines {
      '_BACKYARD_PLATFORM_WINDOWS',
      'WIN32_LEAN_AND_MEAN',
    }

  filter 'system:Linux'
    systemversion 'latest'

    defines {
      '_BACKYARD_PLATFORM_LINUX',
    }

  filter 'configurations:Debug'
    runtime 'Debug'
    symbols 'On'

    defines {
      '_BACKYARD_CONFIGURATION_DEBUG',
    }

  filter 'configurations:Release'
    runtime 'Release'
    optimize 'On'

    defines {
      '_BACKYARD_CONFIGURATION_RELEASE',
    }

    resetFilter()
end

function use_precompiled_header()
  resetFilter()
  local pchSourceLocation = '%{prj.location}/Source'
  pchheader 'pch.h'
  pchsource (pchSourceLocation .. '/pch.cpp')

  files {
    pchSourceLocation .. '/pch.cpp',
    pchSourceLocation .. '/pch.h',
  }
end

function configure_static_library()
  resetFilter()
  kind 'StaticLib'

  defines {
    '_BACKYARD_BUILD_LIBRARY',
    '_BACKYARD_KIND_STATIC_LIBRARY',
  }
end

function configure_dynamic_library()
  resetFilter()
  kind 'SharedLib'

  defines {
    '_BACKYARD_BUILD_LIBRARY',
    '_BACKYARD_KIND_SHARED_LIBRARY',
  }
end

function configure_executable_console()
  resetFilter()
  kind 'ConsoleApp'

  defines {
    '_BACKYARD_KIND_CONSOLE_APP',
  }
end

function configure_executable_windowed()
  resetFilter()
  kind 'WindowedApp'

  defines {
    '_BACKYARD_KIND_WINDOWED_APP',
  }
end