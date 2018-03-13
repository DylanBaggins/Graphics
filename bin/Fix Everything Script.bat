conan install .. --build=missing
cmake .. -G "Visual Studio 14 Win64"
cmake --build . --config Debug

pause