cmake_minimum_required(VERSION 3.15)
project(nias-cpp-example LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

# ---------------------------------------------------------------------------
# Do a release build if nothing was specified
# ---------------------------------------------------------------------------

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "nias-cpp: setting build type to 'Release' as none was specified.")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

add_subdirectory(nias-cpp)

nias_cpp_add_module(nias_cpp_example src/nias-cpp-example/vector.h src/nias-cpp-example/vector.cpp)
target_include_directories(nias_cpp_example PUBLIC src)

add_executable(test_gram_schmidt tests/gram_schmidt_test.cpp)
target_link_libraries(test_gram_schmidt PRIVATE nias_cpp_example)
