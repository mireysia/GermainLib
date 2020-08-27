#--------------------------------------------------------------------
# CMake Version
#--------------------------------------------------------------------

cmake_minimum_required(VERSION 3.12...3.17)

if( ${CMAKE_VERSION} VERSION_LESS 3.12 )
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

#--------------------------------------------------------------------
# Properties
#--------------------------------------------------------------------
set(CMAKE_C_COMPILER "gcc")

set( CMAKE_POSITION_INDEPENDENT_CODE ON )
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

include( "${CMAKE_CURRENT_LIST_DIR}/cmake/project-meta-info.in" )

#--------------------------------------------------------------------
# Project
#--------------------------------------------------------------------

project(    GermainLib
    VERSION ${project_version} 
    DESCRIPTION ${project_description} 
    HOMEPAGE_URL ${project_homepage} 
    LANGUAGES C )
    
#--------------------------------------------------------------------
# Add subdirectories
#--------------------------------------------------------------------

add_subdirectory( apps)

#--------------------------------------------------------------------
# Package
#--------------------------------------------------------------------

find_package( Threads ) #pthread.h

#--------------------------------------------------------------------
# Program Core
#--------------------------------------------------------------------

file(GLOB_RECURSE SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
file(GLOB_RECURSE HEADER "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

#--------------------------------------------------------------------
# Object Library
#--------------------------------------------------------------------

add_library( germainLib_ObjLib OBJECT )

target_sources( germainLib_ObjLib
	PRIVATE 
		${SOURCE}
	PUBLIC 
		${HEADER} )

#--------------------------------------------------------------------
# Object Library Include
#--------------------------------------------------------------------

target_include_directories( germainLib_ObjLib 
	PUBLIC 
		"${CMAKE_CURRENT_SOURCE_DIR}/include" )

#--------------------------------------------------------------------
# Object Library Compile Features
#-------------------------------------------------------------------- 

target_compile_features( germainLib_ObjLib 
	PUBLIC 
		c_std_99 )

#--------------------------------------------------------------------
# Create Shared Library
#--------------------------------------------------------------------

add_library( germainLib SHARED )

target_link_libraries( germainLib 
	PUBLIC 
		germainLib_ObjLib
		${CMAKE_THREAD_LIBS_INIT} )

#--------------------------------------------------------------------
# Create ALIAS Target
#--------------------------------------------------------------------

add_library( GermainLib::germainLib ALIAS germainLib )