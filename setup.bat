@echo off

echo Installing dependencies...
conan install . --install-folder Build/conan/Debug --settings=build_type=Debug --build missing
conan install . --install-folder Build/conan/Release --settings=build_type=Release --build missing

echo.
echo Dependencies installed!
echo Generating files...
.\Tools\premake\bin\premake5.exe vs2022

echo.
echo Generated!