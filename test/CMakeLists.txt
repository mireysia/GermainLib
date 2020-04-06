# Tests need to be added as executables first
add_executable(testlib test.c)

# I'm using C++17 in the test
target_compile_features(testlib PRIVATE c_std_99)

# Should be linked to the main library
target_link_libraries(testlib PRIVATE germain_library)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME testlibtest COMMAND testlib) # Command can be a target
