FROM ubuntu:disco

LABEL maintainer="Andrey Bronin <jonnib@yandex.ru>"

RUN apt-get update && \
    apt-get install -y nano git build-essential cmake protobuf-compiler python3-pip && \
    pip3 install conan

RUN conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan

#RUN apt-get update && apt-get install -y cmake make g++ nano
# RUN apt-get install -y libboost-all-dev googletest libbotan-2-dev
# RUN apt-get install -y nlohmann-json-dev

# RUN apk update && apk add --virtual build-dependencies build-base g++ cmake

COPY ./ /pulsar
WORKDIR /pulsar

RUN conan install . --build=missing -s compiler.libcxx=libstdc++11
RUN cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local/ .
RUN cmake --build .
