include_directories("${PROJECT_SOURCE_DIR}/3rdparty/gtest/include/")
include_directories("${PROJECT_SOURCE_DIR}/src/")

set(TESTS_SOURCES
    bits_test.cpp
    counts_test.cpp
    strings_test.cpp
    shifts_test.cpp
    binary_test.cpp
    compare_test.cpp
    arithmetic_test.cpp
    increments_test.cpp
    )

source_group(sources FILES ${TESTS_SOURCES})

add_executable(tests ${TESTS_SOURCES})

target_link_libraries (tests gtest bignumber)

