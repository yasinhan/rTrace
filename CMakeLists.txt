cmake_minimum_required(VERSION 3.25)
project(ray_trace CXX)


set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(.)

enable_testing()
add_executable(
        tests
        src/test/tuple_test.cpp
        src/test/color_test.cpp
        src/test/canvas_test.cpp
        src/test/matrix_test.cpp
        src/test/transformation_test.cpp
        src/primitive/tuple.cpp
        src/primitive/color.cpp
        src/primitive/matrix.cpp
        src/primitive/vector.cpp
        src/primitive/matrix_sub.cpp
        src/primitive/transformation.cpp
        src/math.h
        src/canvas.cpp
)

target_link_libraries(
        tests
        gtest
        GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(tests)