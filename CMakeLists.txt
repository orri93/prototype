cmake_minimum_required(VERSION 3.8.2)

project(Prototypes
  VERSION 1.0.0.0
  DESCRIPTION "Prototypes"
  LANGUAGES C CXX)

# Build Options
option(BUILD_TESTS "Build tests" OFF)
option(BUILD_PROTOTYPE "Build prototype" OFF)
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

# GOS Test Options
option(GOS_USE_GTEST_DISCOVER
  "Use CMake Google Test descovery for unit tests" OFF)
option(GOS_USE_GTEST_PACKAGE
  "Use CMake GTest Package for unit tests" OFF)

set(CMAKE_PLATFORM_INDEPENDENT_CODE ON)

if (BUILD_TESTS)
  enable_testing()
  if (GOS_USE_GTEST_PACKAGE)
    find_package(GTest REQUIRED)
  else ()
    if (MSVC)
      set(gtest_force_shared_crt ON CACHE BOOL "Use Shared CRT")
    endif (MSVC)
    if (GOS_INSTRUCT_GOOGLE_TEST_PATH)
      set(GOS_GOOGLE_TEST_PATH
        "${GOS_INSTRUCT_GOOGLE_TEST_PATH}")
    else ()
      set(GOS_GOOGLE_TEST_PATH
        "${CMAKE_CURRENT_SOURCE_DIR}/extern/googletest")
      add_subdirectory(extern/googletest)
    endif ()
    set(gos_unit_testing_gmock_include_dir
      "${GOS_GOOGLE_TEST_PATH}/googlemock/include")
    set(gos_unit_testing_gtest_include_dir
      "${GOS_GOOGLE_TEST_PATH}/googletest/include")
    list(APPEND gos_gtest_include
      ${gos_unit_testing_gmock_include_dir}
      ${gos_unit_testing_gtest_include_dir})
    list(APPEND gos_gtest_libraries
      gtest
      gmock
      gmock_main)
  endif ()
endif ()

add_subdirectory(find-display)

message(STATUS "")
message(STATUS "Prototype BUILD SUMMARY")
message(STATUS "  Install prefix            : ${CMAKE_INSTALL_PREFIX}")

message(STATUS "  CMAKE_GENERATOR           : ${CMAKE_GENERATOR}")
message(STATUS "  CMAKE_SOURCE_DIR          : ${CMAKE_SOURCE_DIR}")
message(STATUS "  CMAKE_CURRENT_SOURCE_DIR  : ${CMAKE_CURRENT_SOURCE_DIR}")

message(STATUS "  BUILD_SHARED_LIBS         : ${BUILD_SHARED_LIBS}")

message(STATUS "  C   Compiler ID           : ${CMAKE_C_COMPILER_ID}")
message(STATUS "  C   Compiler Version      : ${CMAKE_C_COMPILER_VERSION}")
message(STATUS "  C   Compiler flags        : ${CMAKE_C_FLAGS}")
message(STATUS "  C++ Compiler ID           : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "  C++ Compiler Version      : ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "  C++ Compiler flags        : ${CMAKE_CXX_FLAGS}")

if (BUILD_TESTS)
message(STATUS "Building Tests")
if (MSVC_VERSION)
message(STATUS "  GTest Force Shared CRT    : ${gtest_force_shared_crt}")
endif ()
endif ()
endif (BUILD_TESTS)
message(STATUS "")

if (BUILD_PROTOTYPE)
message(STATUS "Building Prototype")
endif ()
