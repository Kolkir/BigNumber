set(CORE_SOURCES
    ${PROJECT_SOURCE_DIR}/src/bignumber.h
    ${PROJECT_SOURCE_DIR}/src/bignumber.cpp
    )

source_group(sources FILES ${CORE_SOURCES})    
   
add_library(bignumber STATIC ${CORE_SOURCES})

