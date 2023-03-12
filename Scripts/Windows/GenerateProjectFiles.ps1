echo [Info] Generating project files...

& .\Tools\premake\bin\Windows\premake5.exe vs2022

# Fix for premake not setting precompiled header to create
(Get-Content .\Projects\Engine\Engine.vcxproj).replace('<PrecompiledHeader>Use</PrecompiledHeader>', '<PrecompiledHeader>Create</PrecompiledHeader>') | Set-Content .\Projects\Engine\Engine.vcxproj