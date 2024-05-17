cmake_minimum_required(VERSION 3.20.0)

#### Download GoogleTest with the revision (git hash) in the URL
set(CMAKE_C_FLAGS -m32)
set(CMAKE_CXX_FLAGS -m32)
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BOARD native_posix)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)


# Build zephyr application
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hello_world)
include_directories(include)
target_sources(app PRIVATE src/main.c src/max.c)

# gtest
enable_testing()

# Compile hello_test.cpp test code to hello_test binary
add_executable(
  hello_test 
  tests/hello_test.cpp 
)

# Link hello_test to googletest library
target_link_libraries(
  hello_test
  GTest::gtest_main
)

# Link hello_test to app (which holds all the zephyr compilated stuff)
target_link_libraries(hello_test app)

include(GoogleTest)
gtest_discover_tests(hello_test)