work_directory='%{wks.location}/App'

project_location='%{wks.location}/Projects/%{prj.name}'
project_output_directory_template='%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}'
project_binary_directory='%{wks.location}/Build/bin/' .. project_output_directory_template .. '/%{prj.name}'
project_object_directory='%{wks.location}/Build/bin-int/' .. project_output_directory_template .. '/%{prj.name}'

function resetFilter()
  filter {}
end

function project_defaults()
  location (project_location)

  language 'C++'
  cppdialect 'C++20'

  targetdir (project_binary_directory)
  objdir (project_object_directory)

  files {
    '%{prj.location}/*.h',
    '%{prj.location}/*.hpp',
    '%{prj.location}/*.cpp',
    '%{prj.location}/**/*.h',
    '%{prj.location}/**/*.hpp',
    '%{prj.location}/**/*.cpp',
  }

  includedirs {
    '%{prj.location}/src',
  }

  filter 'system:Windows'
    systemversion 'latest'

    defines {
      '_ENGINE_PLATFORM_WINDOWS',
      'WIN32_LEAN_AND_MEAN',
    }

  filter 'system:Linux'
    systemversion 'latest'

    defines {
      '_ENGINE_PLATFORM_LINUX',
    }

  filter 'configurations:Debug'
    runtime 'Debug'
    symbols 'On'

    defines {
      '_ENGINE_CONFIGURATION_DEBUG',
    }

  filter 'configurations:Release'
    runtime 'Release'
    optimize 'On'

    defines {
      '_ENGINE_CONFIGURATION_RELEASE',
    }

    resetFilter()
end

function use_precompiled_header()
  local pchSourceLocation = '%{prj.location}/'
  pchheader 'pch.h'
  pchsource (pchSourceLocation .. '/pch.cpp')
end

function configure_static_library()
  kind 'StaticLib'

  defines {
    '_ENGINE_BUILD_LIBRARY',
    '_ENGINE_KIND_STATIC_LIBRARY',
  }
end

function configure_dynamic_library()
  kind 'SharedLib'

  defines {
    '_ENGINE_BUILD_LIBRARY',
    '_ENGINE_KIND_SHARED_LIBRARY',
  }
end

function configure_executable_console()
  kind 'ConsoleApp'

  defines {
    '_ENGINE_KIND_CONSOLE_APP',
  }
end

function configure_executable_windowed()
  kind 'WindowedApp'

  defines {
    '_ENGINE_KIND_WINDOWED_APP',
  }
end