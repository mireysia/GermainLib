cmake_minimum_required(VERSION 3.12...3.17)

if( ${CMAKE_VERSION} VERSION_LESS 3.12 )
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

#force to use gcc
set(CMAKE_C_COMPILER "gcc")

set( CMAKE_POSITION_INDEPENDENT_CODE ON )

include( "${CMAKE_CURRENT_LIST_DIR}/cmake/project-meta-info.in" )

# Define a project for the current CMakeLists.txt.
project(    GermainLib
    VERSION ${project_version} 
    DESCRIPTION ${project_description} 
    HOMEPAGE_URL ${project_homepage} 
    LANGUAGES C )
    
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

file(GLOB_RECURSE SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
file(GLOB_RECURSE HEADER "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

add_library( germainLib_ObjLib OBJECT )

target_sources( germainLib_ObjLib
	PRIVATE 
		${SOURCE}
	PUBLIC 
		${HEADER} )

# Required include search-paths and constexpr support.
target_include_directories( germainLib_ObjLib 
	PUBLIC 
		"${CMAKE_CURRENT_SOURCE_DIR}/include" )

target_compile_features( germainLib_ObjLib 
	PUBLIC 
		c_std_99 )

# A shared library for basic-math functionality.
add_library( germainLib SHARED )

target_link_libraries( germainLib 
	PUBLIC 
		germainLib_ObjLib )

# Create ALIAS targets.
add_library( GermainLib::germainLib ALIAS germainLib )

add_subdirectory( apps)