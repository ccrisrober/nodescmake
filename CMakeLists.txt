cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(NODES VERSION 1.9.2 )
set(NODES_VERSION_ABI 1)

# Disable in source building
if( "${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}" )
	message( FATAL "no in source building allowed." )
endif()

list(APPEND CMAKE_MODULE_PATH
	${PROJECT_SOURCE_DIR}/CMake
	${CMAKE_SOURCE_DIR}/CMake/common)

# Default build type is Debug
if( NOT CMAKE_BUILD_TYPE )
	set( CMAKE_BUILD_TYPE Debug )
endif( NOT CMAKE_BUILD_TYPE )

if ( CMAKE_BUILD_TYPE MATCHES "Debug" )
	add_definitions( -DDEBUG )
endif( )

include(GitExternal)

set(NODES_DESCRIPTION "nodes")
set(COMMON_PROJECT_DOMAIN maldicion069)

include(Common)

# Allow warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")

#common_find_package( tinyxml2 REQUIRED  )

#list (APPEND NODES_DEPENDENT_LIBRARIES tinyxml2)

common_find_package_post( )

add_subdirectory( nodes )
#add_subdirectory( physics )
add_subdirectory( examples )

set(DOXYGEN_MAINPAGE_MD ${PROJECT_SOURCE_DIR}/README.md)
set(DOXYGEN_EXTRA_INPUT ${DOXYGEN_MAINPAGE_MD})
include(CPackConfig)
include(DoxygenRule)
