work_directory='%{wks.location}/App'

project_location='%{wks.location}/Source/%{prj.name}'
project_output_directory_template='%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}'
project_binary_directory='%{wks.location}/Build/bin/' .. project_output_directory_template .. '/%{prj.name}'
project_object_directory='%{wks.location}/Build/bin-int/' .. project_output_directory_template .. '/%{prj.name}'

local function include_conan(filename)
  include(filename)
  local buildinfo = { }
  local prefix = 'conan_'
  for k, v in pairs(_G) do
      if k:sub(1, #prefix) == prefix then
          buildinfo[k:sub(#prefix + 1)] = v
      end
  end
  return buildinfo
end

conan_debug   = include_conan('Build/conan/Debug/conanbuildinfo.premake.lua')
conan_release = include_conan('Build/conan/Release/conanbuildinfo.premake.lua')

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
    '%{prj.location}/',
    '%{prj.location}/Public',
    '%{prj.location}/Private',
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
  local pchSourceLocation = '%{prj.location}/'
  pchheader 'pch.h'
  pchsource (pchSourceLocation .. '/pch.cpp')

  files {
    pchSourceLocation .. '/pch.cpp',
    pchSourceLocation .. '/pch.h',
  }
end

function configure_static_library()
  kind 'StaticLib'

  defines {
    '_BACKYARD_BUILD_LIBRARY',
    '_BACKYARD_KIND_STATIC_LIBRARY',
  }
end

function configure_dynamic_library()
  kind 'SharedLib'

  defines {
    '_BACKYARD_BUILD_LIBRARY',
    '_BACKYARD_KIND_SHARED_LIBRARY',
  }
end

function configure_executable_console()
  kind 'ConsoleApp'

  defines {
    '_BACKYARD_KIND_CONSOLE_APP',
  }
end

function configure_executable_windowed()
  kind 'WindowedApp'

  defines {
    '_BACKYARD_KIND_WINDOWED_APP',
  }
end