cmake_minimum_required(VERSION 3.14)

project(sdp-tools-cppTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(sdp-tools-cpp REQUIRED)
  enable_testing()
endif()

# ---- Tests ----

add_executable(sdp-tools-cpp_test source/sdp-tools-cpp_test.cpp)
target_link_libraries(sdp-tools-cpp_test PRIVATE sdp-tools-cpp::sdp-tools-cpp)
target_compile_features(sdp-tools-cpp_test PRIVATE cxx_std_20)

add_test(NAME sdp-tools-cpp_test COMMAND sdp-tools-cpp_test)

# ---- End-of-file commands ----

add_folders(Test)
