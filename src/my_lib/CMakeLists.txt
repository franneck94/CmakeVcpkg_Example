add_library(${LIBRARY_NAME} STATIC my_lib.cc)
target_include_directories(${LIBRARY_NAME} PUBLIC "./")

if (${ENABLE_WARNINGS})
    target_set_warnings(TARGET ${LIBRARY_NAME} ENABLE ON AS_ERROR OFF)
endif()

if(${ENABLE_LTO})
    target_enable_lto(${LIBRARY_NAME} optimized)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_target_properties(${LIBRARY_NAME} PROPERTIES
        VS_GLOBAL_RunCodeAnalysis false
        VS_GLOBAL_EnableMicrosoftCodeAnalysis true
        VS_GLOBAL_EnableClangTidyCodeAnalysis true
    )
endif()
