@echo off
pushd %~dp0\..\..\
call Tools\BuildTool\bin\windows\premake5.exe --file=Tools\BuildTool\config\premake5.lua vs2022
popd
PAUSE