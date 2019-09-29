cmake_minimum_required(VERSION 3.14)
project(pulsar-cpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")


option(PULSAR_WITH_TESTS "Build pulsar unit tests" ON)

set (CMAKE_CXX_FLAGS "-g -Wall -DBOOST_LOG_DYN_LINK")


#set(Boost_USE_STATIC_LIBS        ON) # only find static libs
#find_package(Boost 1.67 COMPONENTS REQUIRED)
find_package(Boost 1.71 COMPONENTS program_options filesystem REQUIRED)

find_package(nlohmann_json 3.7.0 REQUIRED) # ubuntu apt has 2.1.1
find_package(yaml-cpp 0.6.0 REQUIRED)
find_package(Botan 2.1.1 REQUIRED)
#find_package(CryptoPP REQUIRED)
find_package(Protobuf REQUIRED)


file(GLOB ProtoFiles "${CMAKE_SOURCE_DIR}/proto/*.proto")
PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER ${ProtoFiles})
add_library(proto ${PROTO_HEADER} ${PROTO_SRC})

set (LIB_TARGET_NAME pulsar)
set (CMD_TARGET_NAME pulsard)

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_CURRENT_BINARY_DIR}
        ${PROTOBUF_INCLUDE_DIR}
        ${BOTAN_INCLUDE_DIRS}
#        ${CRYPTO++_INCLUDE_DIRS}
        )

include(collect_sources)
CollectSources(Sources Headers ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src/lib)
CollectSources(PublicSources PublicHeaders ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${LIB_TARGET_NAME} STATIC ${Sources} ${Sources} ${PublicHeaders})

add_executable(${CMD_TARGET_NAME} src/cmd/main.cpp)
target_link_libraries(${CMD_TARGET_NAME} PUBLIC ${LIB_TARGET_NAME} proto
        nlohmann_json::nlohmann_json
        ${YAML_CPP_LIBRARIES}
        ${Boost_LIBRARIES}
        ${BOTAN_LIBRARIES}
#        ${CRYPTO++_LIBRARIES}
        ${PROTOBUF_LIBRARY}
        ${LIB_TARGET_NAME}
        )

# Setup testing
if(PULSAR_WITH_TESTS)
        enable_testing()
        add_subdirectory(test)
endif()
