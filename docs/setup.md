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


------


# raspi (Raspberry os x64)


cmake -> 3.18.4
latest vcpkg needs cmake 3.20+
-> pip3 install cmake 
-> sudo ln -s ~/.local/bin/c* /usr/bin



[cmake]       libxmu-dev
[cmake]       libxi-dev
[cmake]       libgl-dev


sudo apt-get install libxmu-dev libxi-dev libgl-dev



[build] GLFW3 currently requires the following libraries from the system package manager:
[build]     libxinerama-dev
[build]     libxcursor-dev
[build]     xorg-dev
[build]     libglu1-mesa-dev

sudo apt-get install libglu1-mesa
