project(test_pulsar CXX)

find_package(GTest 1.8.1 REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# https://cmake.org/cmake/help/v3.14/module/GoogleTest.html

include(GoogleTest)
add_executable(${PROJECT_NAME} cryptography_test.cpp config_test.cpp)
target_link_libraries(${PROJECT_NAME} gtest::gtest Insolar::pulsar)
#        ${botan_LIBRARIES}
#        ${PROTOBUF_LIBRARY}
#        ${YAML_CPP_LIBRARIES}
#        yaml-cpp::yaml-cpp
#        proto
#        ${Boost_LIBRARIES}
#        )

gtest_add_tests(TARGET      ${PROJECT_NAME}
        TEST_SUFFIX .noArgs
        TEST_LIST   noArgsTests
        )

#add_executable (${PROJECT_NAME}
#        main_test.cpp
#        config_test.cpp
#        )

#target_link_libraries(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES})
#
#add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME} --gtest_output=xml)