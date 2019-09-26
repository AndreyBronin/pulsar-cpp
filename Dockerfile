# FROM ubuntu:disco
# FROM alpine

# RUN apt-get update && apt-get install -y cmake make g++ nano
# RUN apt-get install -y libboost-all-dev googletest libbotan-2-dev
# RUN apt-get install -y nlohmann-json-dev

# RUN apk update && apk add --virtual build-dependencies build-base g++ cmake

COPY ./ /pulsar
