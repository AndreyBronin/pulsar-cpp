cmake_minimum_required(VERSION 3.13.4)
project(pulsar-cpp VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

option(PULSAR_WITH_TESTS "Build pulsar unit tests" OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(boost 1.71 COMPONENTS program_options filesystem REQUIRED)
#
find_package(jsonformoderncpp 3.7.0 REQUIRED)
find_package(yaml-cpp 0.6.0 REQUIRED)
find_package(botan 2.1.1 REQUIRED)
##find_package(CryptoPP REQUIRED)
find_package(Protobuf REQUIRED)

# proto lib
file(GLOB ProtoFiles "${CMAKE_SOURCE_DIR}/proto/*.proto")
PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER ${ProtoFiles})
add_library(proto ${PROTO_HEADER} ${PROTO_SRC})
add_library(Insolar::proto ALIAS proto)
target_include_directories(proto PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(proto PUBLIC protobuf::libprotobuf)

include(collect_sources)
CollectSources(Sources Headers ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src/lib)
CollectSources(PublicSources PublicHeaders ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)

# pulsar lib
add_library(pulsar ${Sources} ${Sources} ${PublicHeaders})
add_library(Insolar::pulsar ALIAS pulsar)
target_include_directories(pulsar PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(pulsar PUBLIC botan::botan yaml-cpp::yaml-cpp boost::boost jsonformoderncpp::jsonformoderncpp Insolar::proto)

# pulsard cmd
add_executable(pulsard src/cmd/main.cpp)
target_link_libraries(pulsard PUBLIC Insolar::pulsar)


# Setup testing
if(PULSAR_WITH_TESTS)
        enable_testing()
        add_subdirectory(test)
endif()
