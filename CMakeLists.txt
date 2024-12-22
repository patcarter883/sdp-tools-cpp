cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    sdp-tools-cpp
    VERSION 0.1.0
    DESCRIPTION "Short description"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    sdp-tools-cpp_sdp-tools-cpp
    src/SessionDescription.cpp
)
add_library(sdp-tools-cpp::sdp-tools-cpp ALIAS sdp-tools-cpp_sdp-tools-cpp)

include(GenerateExportHeader)
generate_export_header(
    sdp-tools-cpp_sdp-tools-cpp
    BASE_NAME sdp-tools-cpp
    EXPORT_FILE_NAME export/sdp-tools-cpp/sdp-tools-cpp_export.hpp
    CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(sdp-tools-cpp_sdp-tools-cpp PUBLIC SDP_TOOLS_CPP_STATIC_DEFINE)
endif()

set_target_properties(
    sdp-tools-cpp_sdp-tools-cpp PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}"
    EXPORT_NAME sdp-tools-cpp
    OUTPUT_NAME sdp-tools-cpp
)

target_include_directories(
    sdp-tools-cpp_sdp-tools-cpp ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_include_directories(
    sdp-tools-cpp_sdp-tools-cpp SYSTEM
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/export>"
)

target_compile_features(sdp-tools-cpp_sdp-tools-cpp PUBLIC cxx_std_20)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Examples ----

if(PROJECT_IS_TOP_LEVEL)
  option(BUILD_EXAMPLES "Build examples tree." "${sdp-tools-cpp_DEVELOPER_MODE}")
  if(BUILD_EXAMPLES)
    add_subdirectory(example)
  endif()
endif()

# ---- Developer mode ----

if(NOT sdp-tools-cpp_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of sdp-tools-cpp"
  )
endif()

include(cmake/dev-mode.cmake)
