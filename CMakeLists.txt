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
        src/test/primitive/tuple_test.cpp
        src/test/primitive/color_test.cpp
        src/test/primitive/matrix_test.cpp
        src/test/primitive/ray_test.cpp
        src/test/primitive/transformation_test.cpp
        src/test/primitive/intersection_test.cpp
        src/test/scene/world_test.cpp
        src/test/scene/camera_test.cpp
        src/test/scene/prepare_computations_test.cpp
        src/test/image/ppm_writer_test.cpp
        src/test/shape/sphere_test.cpp
        src/test/shape/material_test.cpp
        src/test/display/projectile_test.cpp
        src/test/display/canvas_test.cpp
        src/test/light/light_test.cpp
        src/test/shape/plane_test.cpp
)

add_library(
        basic
        src/primitive/tuple.cpp
        src/primitive/color.cpp
        src/primitive/matrix.cpp
        src/primitive/vector.cpp
        src/primitive/matrix_sub.cpp
        src/primitive/transformation.cpp
        src/primitive/ray.cpp
        src/primitive/intersection.cpp
        src/primitive/intersections.cpp
        src/math.h
        src/display/canvas.cpp
        src/display/projectile.cpp
        src/shape/sphere.cpp
        src/shape/material.cpp
        src/shape/shape.cpp
        src/light/light.cpp
        src/image/ppm_writer.cpp
        src/scene/world.cpp
        src/scene/camera.cpp
        src/scene/prepare_computations.cpp
        src/shape/plane.cpp
)

add_executable(
        display
        src/application/render.cpp
)

target_link_libraries(
        tests
        gtest
        GTest::gtest_main
        basic
)

target_link_libraries(
        display
        basic
)

include(GoogleTest)
gtest_discover_tests(tests)