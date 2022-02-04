behavior:

- vcpkg is cloned using git submodule
- install dependent library via vcpkg.json



pre-requisites:
--------------------

ubuntu: 

* CMake ver. 3.xx
* zip/unzip to expand vcpkg
  * sudo apt-get install curl zip unzip tar
* pkg-config
    sudo apt-get install pkg-config
* for OpenGL on WSL ubuntu
    sudo apt-get install libgl1-mesa-dev
* ninja
    sudo apt-get install ninja

git clone --recursive 
git submodule update --init --recursive

