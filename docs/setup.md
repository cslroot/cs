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

```
git clone --recursive https://github.com/cslroot/cs.git
```

if you already cloned without `--recursive` option, then use below
```
git submodule update --init --recursive
```

vcpkg bind
```
.\bootstrap-vcpkg.bat
```

# Windows


```PowerShell
winget install cmake

```


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





# WSLg

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



Ubuntu
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
