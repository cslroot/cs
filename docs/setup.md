behavior:

- vcpkg is cloned using git submodule
- install dependent library via vcpkg.json

## pre-requisites:

ubuntu:

- CMake ver. 3.xx
- zip/unzip to expand vcpkg
  - sudo apt-get install curl zip unzip tar
- pkg-config
  sudo apt-get install pkg-config
- for OpenGL on WSL ubuntu
  sudo apt-get install libgl1-mesa-dev
- ninja
  sudo apt-get install ninja

git clone --recursive
git submodule update --init --recursive

# Windows

## Ninja + clang


PS> & 'C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat'

cmd> "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" x64

cmake --preset="win-x64-ninja"
cmake --build --preset="win-ninja"
