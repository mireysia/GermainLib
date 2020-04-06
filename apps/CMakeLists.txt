set(EXECUTABLE_OUTPUT_PATH ${GermainLib_SOURCE_DIR})
add_executable(main main.c)
target_compile_features(main PRIVATE c_std_99)

target_link_libraries(main PUBLIC germain_library)
