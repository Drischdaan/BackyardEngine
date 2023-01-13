project 'spdlog'
  location (thirdPartyProjectLocation)

  kind 'StaticLib'

  language 'c++'
  cppdialect 'C++Latest'

  targetdir (buildDirectory)
  objdir (objectBuildDirectory)

  files {
    '%{prj.location}/include/**/*.h',
    '%{prj.location}/include/**/*.rst',
    '%{prj.location}/src/*.cpp',
  }

  includedirs {
    '%{prj.location}/include/',
  }

  defines {
    'SPDLOG_COMPILED_LIB'
  }