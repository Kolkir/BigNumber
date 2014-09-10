include_directories("${PROJECT_SOURCE_DIR}/3rdparty/gtest/include/")
include_directories("${PROJECT_SOURCE_DIR}/3rdparty/gtest/")

set(GTEST_SOURCES
    ${PROJECT_SOURCE_DIR}/3rdparty/gtest/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/3rdparty/gtest/src/gtest_main.cc)
    
add_library(gtest STATIC ${GTEST_SOURCES})
