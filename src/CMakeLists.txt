# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

file(GLOB_RECURSE HEADER CONFIGURE_DEPENDS "${GermainLib_SOURCE_DIR}/include/germainLib/*.h")
file(GLOB_RECURSE SOURCE "${GermainLib_SOURCE_DIR}/src/*.c")

# Make an automatic library - will be static or dynamic based on user setting
add_library(germain_library ${SOURCE} ${HEADER})

# We need this directory, and users of our library will need it too
target_include_directories(germain_library PUBLIC ../include)

# All users of this library will need at least C99
target_compile_features(germain_library PUBLIC c_std_99)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER})
