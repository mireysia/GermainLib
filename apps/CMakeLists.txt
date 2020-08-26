set(EXECUTABLE_OUTPUT_PATH ${GermainLib_SOURCE_DIR})

add_executable( germain )

target_sources( germain 
    PRIVATE 
        "main.c" ) 

target_link_libraries( germain
    PRIVATE 
        GermainLib::germainLib )