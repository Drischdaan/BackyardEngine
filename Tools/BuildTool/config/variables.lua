defaultProjectLocation = '%{wks.location}/Projects/%{prj.name}'
thirdPartyProjectLocation = '%{wks.location}/Projects/ThirdParty/%{prj.name}'

outputDirectory       ='%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}'
buildDirectory        ='%{wks.location}/build/bin/' .. outputDirectory .. '/%{prj.name}'
objectBuildDirectory  ='%{wks.location}/build/bin-int/' .. outputDirectory .. '/%{prj.name}'
