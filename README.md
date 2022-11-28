# Steps

- .\external\vcpkg\vcpkg.exe x-update-baseline --add-initial-baseline
- make prepare
- mkdir build
- cd build
- cmake -B . -S .. -DCMAKE_TOOLCHAIN_FILE=C:/Users/Jan/Documents/_LocalCoding/vcpkg/scripts/buildsystems/vcpkg.cmake"
- cmake --build .
