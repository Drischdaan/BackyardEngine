@echo off

echo [Info] Installing dependencies...

conan install . --install-folder Build/conan/Debug --settings=build_type=Debug --build missing
conan install . --install-folder Build/conan/Release --settings=build_type=Release --build missing