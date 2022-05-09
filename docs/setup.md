
# How to build from source

## In short

### Linux

```
git clone --recursive https://github.com/cslroot/cs.git
cd cs
cmake --preset "clang-x64-ninja"
cmake --build --preset "clang-x64-ninja-Release"
```

### Windows

using Visual Studio 2022

```
git clone --recursive https://github.com/cslroot/cs.git
cd cs
cmake --preset "windows-x64-vs2019"
cmake --build --preset "windows-x64-vs2019-Release"
```


## get source from git

```
git clone --recursive https://github.com/cslroot/cs.git
```

This repo use vcpkg as submodule, so clone with recursive option.
Dependent libraries are retrieved via vcpkg.json.


When you already cloned without `--recursive` option, then use below to get vcpkg:

```
git submodule update --init --recursive
```


## pre-requisites:

If you want to build locally, please introduce the followings:

- CMake ver. 3.20 or above
  - to use CMakePreset
- need zip/unzip to expand package of vcpkg (Linux)
  - `sudo apt-get install curl zip unzip tar`
- ninja
  - `sudo apt-get install ninja`


vcpkg bind
```
.\bootstrap-vcpkg.bat
```

no need to call integrate ~`.\vcpkg.exe integrate install`~


# Windows

## using Visual Studio 2022(VS2022)

### install build tools
I used VS2022 Community Edition. It is easist way to build.
And install cmake and Ninja via VS2022 Installer.

* `ツール >  ツールと機能を取得`
* checked `ワークロード > C++ によるデスクトップ開発`
  * install MSVC and 
* check `Windows 用 C++ CMake ツール` if unchecked


### build

```PowerShell:
"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
cmake --preset="win-x64-ninja"
cmake --build --preset="win-ninja"
```


## using local??

```PowerShell
winget install cmake
winget install LLVM
```

## Ninja + clang


------


# raspi (Raspberry os x64)

## ubuntu 22.04 LTS

install env.

```
sudo apt install -y cmake ninja-build clang
sudo apt install -y curl zip unzip tar
sudo apt install -y pkg-config
sudo apt install -y libxmu-dev libxi-dev libgl-dev
sudo apt install -y libxinerama-dev libxcursor-dev xorg-dev libglu1-mesa-dev
``

build

```
cmake --preset="raspi-clang-arm64-ninja"
cmake --build --preset="raspi-clang-arm64-ninja-Debug"
```


-----

## raspberry pi OS

cmake -> 3.18.4
latest vcpkg needs cmake 3.20+
-> pip3 install cmake 
-> sudo ln -s ~/.local/bin/c* /usr/bin

[cmake]       libxmu-dev
[cmake]       libxi-dev
[cmake]       libgl-dev

```
sudo apt install -y libxmu-dev libxi-dev libgl-dev
sudo apt install -y libglu1-mesa
sudo apt install -y libxinerama-dev libxcursor-dev xorg-dev libglu1-mesa-dev
```

[build] GLFW3 currently requires the following libraries from the system package manager:
[build]     libxinerama-dev
[build]     libxcursor-dev
[build]     xorg-dev
[build]     libglu1-mesa-dev





# Ubuntu on WSLg

Test Env.

* Ubuntu 20.04LTS
* Intel(R) Core(TM) i7-10875H
* NVIDIA GeForce RTX 2070 Super



### Note
* WSLg supports OpenGL 3.3 (Core) now (2022-04-01)

result of my laptop (ubuntu 20.04LTS / GeForce 2070 Super laptop)

```
$ glxinfo -B
name of display: :0
display: :0  screen: 0
direct rendering: Yes
Extended renderer info (GLX_MESA_query_renderer):
    Vendor: Microsoft Corporation (0xffffffff)
    Device: D3D12 (NVIDIA GeForce RTX 2070 Super) (0xffffffff)
    Version: 21.2.6
    Accelerated: yes
    Video memory: 24286MB
    Unified memory: no
    Preferred profile: core (0x1)
    Max core profile version: 3.3
    Max compat profile version: 3.1
    Max GLES1 profile version: 1.1
    Max GLES[23] profile version: 3.0
OpenGL vendor string: Microsoft Corporation
OpenGL renderer string: D3D12 (NVIDIA GeForce RTX 2070 Super)
OpenGL core profile version string: 3.3 (Core Profile) Mesa 21.2.6
OpenGL core profile shading language version string: 3.30
OpenGL core profile context flags: (none)
OpenGL core profile profile mask: core profile

OpenGL version string: 3.1 Mesa 21.2.6
OpenGL shading language version string: 1.40
OpenGL context flags: (none)

OpenGL ES profile version string: OpenGL ES 3.0 Mesa 21.2.6
OpenGL ES profile shading language version string: OpenGL ES GLSL ES 3.00
```



Ubuntu x64
----------------

* Docker Desktop on Windows / WSL
* Ubuntu focal
  * `docker pull ubuntu:focal`

```sh
apt install -y git
apt install -y cmake ninja-build clang
apt install -y libxmu-dev libxi-dev libgl-dev
apt install -y libglu1-mesa
apt install -y libxinerama-dev libxcursor-dev xorg-dev libglu1-mesa-dev
```

`cmake --version` is old to build using cmake preset
so that introduce update version of cmake via pip

```
apt purge cmake
apt install -y python3-pip
pip3 install cmake
```


## TIPS

### Update cmake to newer version

if your package manaeger(apt) use older cmake (<3.20), please try to update cmake via pip.

```
$ sudo apt purge cmake  # remove cmake from package manager
$ pip3 install cmake    # install cmake via pip
$ cmake --version
```

-----------

# Testing

test project: `${PROJECT_ROOT}/test`

* google test (installed via vcpkg)
* lcov (for coverage)


## Coverage

CS_CODE_COVERAGE = ON

```
sudo apt install -y lcov
sudo apt install -y llvm  # to use clang gcov
```


> /path/to/XXXX.cpp.gcno:version '408*', prefer 'B12*'
> geninfo: ERROR: GCOV failed for /path/to/XXXX.cpp.gcda!


```
lcov -d . -c -o coverage.info --gcov-tool $PWD/llvm-gcov.sh
genhtml -o lcovHtml --num-spaces 4 -s --legend coverage.info
```
