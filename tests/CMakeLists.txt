include_directories("${PROJECT_SOURCE_DIR}/3rdparty/gtest/include/")
include_directories("${PROJECT_SOURCE_DIR}/src/")

set(TESTS_SOURCES
    bits_test.cpp
    string_test.cpp
    )

source_group(sources FILES ${TESTS_SOURCES})

add_executable(tests ${TESTS_SOURCES})

target_link_libraries (tests gtest bignumber)

