if(PROJECT_IS_TOP_LEVEL)
  set(
      CMAKE_INSTALL_INCLUDEDIR "include/sdp-tools-cpp-${PROJECT_VERSION}"
      CACHE STRING ""
  )
  set_property(CACHE CMAKE_INSTALL_INCLUDEDIR PROPERTY TYPE PATH)
endif()

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# find_package(<package>) call for consumers to find this project
set(package sdp-tools-cpp)

install(
    DIRECTORY
    include/
    "${PROJECT_BINARY_DIR}/export/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    COMPONENT sdp-tools-cpp_Development
)

install(
    TARGETS sdp-tools-cpp_sdp-tools-cpp
    EXPORT sdp-tools-cppTargets
    RUNTIME #
    COMPONENT sdp-tools-cpp_Runtime
    LIBRARY #
    COMPONENT sdp-tools-cpp_Runtime
    NAMELINK_COMPONENT sdp-tools-cpp_Development
    ARCHIVE #
    COMPONENT sdp-tools-cpp_Development
    INCLUDES #
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

# Allow package maintainers to freely override the path for the configs
set(
    sdp-tools-cpp_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/${package}"
    CACHE STRING "CMake package config location relative to the install prefix"
)
set_property(CACHE sdp-tools-cpp_INSTALL_CMAKEDIR PROPERTY TYPE PATH)
mark_as_advanced(sdp-tools-cpp_INSTALL_CMAKEDIR)

install(
    FILES cmake/install-config.cmake
    DESTINATION "${sdp-tools-cpp_INSTALL_CMAKEDIR}"
    RENAME "${package}Config.cmake"
    COMPONENT sdp-tools-cpp_Development
)

install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${sdp-tools-cpp_INSTALL_CMAKEDIR}"
    COMPONENT sdp-tools-cpp_Development
)

install(
    EXPORT sdp-tools-cppTargets
    NAMESPACE sdp-tools-cpp::
    DESTINATION "${sdp-tools-cpp_INSTALL_CMAKEDIR}"
    COMPONENT sdp-tools-cpp_Development
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
