FROM ubuntu:focal

RUN apt-get update && apt-get -y upgrade && \
    apt-get install -y \
        sudo \
        build-essential  \
        vim  wget unzip \
        git libssl-dev \
        gcc g++

ENV CC=/usr/bin/gcc \
    CXX=/usr/bin/g++

# Install newer CMake manually
# https://qiita.com/hyasuda/items/16c21458f0ecd08db857
RUN cd $HOME && \
    wget https://github.com/Kitware/CMake/releases/download/v3.23.1/cmake-3.23.1.tar.gz && \
    tar zxvf cmake-3.23.1.tar.gz && \
    cd cmake-3.23.1/ && \
    ./bootstrap && \
    make -j12 && sudo make install -j8
RUN echo 'export PATH=$HOME/cmake-3.23.1/bin/:$PATH' >> ~/.bashrc && \
    . ~/.bashrc

# set pre-set TimeZone to avoid hang-up when installing xorg-dev that use user prompot.
ENV TZ=Asia/Tokyo
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# install packages to build cs
RUN apt-get install -y \
    ninja-build clang curl zip unzip tar \
    libxmu-dev libxi-dev libgl-dev \
    libxinerama-dev libxcursor-dev xorg-dev libglu1-mesa-dev

RUN mkdir $HOME/dev

WORKDIR $HOME/dev/

CMD bash