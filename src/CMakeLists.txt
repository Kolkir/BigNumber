set(CORE_SOURCES
    ${PROJECT_SOURCE_DIR}/src/decls.h
    ${PROJECT_SOURCE_DIR}/src/bignumber.h
    ${PROJECT_SOURCE_DIR}/src/bignumber.cpp
    ${PROJECT_SOURCE_DIR}/src/bits.cpp
    ${PROJECT_SOURCE_DIR}/src/counts.cpp
    ${PROJECT_SOURCE_DIR}/src/shifts.cpp
    ${PROJECT_SOURCE_DIR}/src/strings.cpp
    ${PROJECT_SOURCE_DIR}/src/binary_op.cpp
    ${PROJECT_SOURCE_DIR}/src/util.h
    ${PROJECT_SOURCE_DIR}/src/util.cpp
    )

source_group(sources FILES ${CORE_SOURCES})

add_library(bignumber STATIC ${CORE_SOURCES})

