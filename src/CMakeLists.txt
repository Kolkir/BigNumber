set(CORE_SOURCES
    ${PROJECT_SOURCE_DIR}/src/decls.h
    ${PROJECT_SOURCE_DIR}/src/number.h
    ${PROJECT_SOURCE_DIR}/src/number.cpp
    ${PROJECT_SOURCE_DIR}/src/bits.cpp
    ${PROJECT_SOURCE_DIR}/src/counts.cpp
    ${PROJECT_SOURCE_DIR}/src/shifts.cpp
    ${PROJECT_SOURCE_DIR}/src/strings.cpp
    ${PROJECT_SOURCE_DIR}/src/binary.cpp
    ${PROJECT_SOURCE_DIR}/src/compare.cpp
    ${PROJECT_SOURCE_DIR}/src/util.h
    ${PROJECT_SOURCE_DIR}/src/util.cpp
    )

source_group(sources FILES ${CORE_SOURCES})

add_library(bignumber STATIC ${CORE_SOURCES})

