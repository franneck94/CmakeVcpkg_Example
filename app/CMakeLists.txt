add_executable(${EXECUTABLE_NAME} main.cc)

target_link_libraries(${EXECUTABLE_NAME}
  PUBLIC
    ${LIBRARY_NAME}
  PRIVATE
    cxxopts::cxxopts
    fmt::fmt
    range-v3::range-v3
    Catch2::Catch2

    ${CPP_HTTPLIB_INCLUDE_DIRS}
    JsonCpp::JsonCpp
    open62541::open62541
    nadjieb_mjpeg_streamer::nadjieb_mjpeg_streamer
)

if (${ENABLE_WARNINGS})
    target_set_warnings(TARGET ${EXECUTABLE_NAME} ENABLE ON AS_ERROR OFF)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES
        VS_GLOBAL_RunCodeAnalysis false
        VS_GLOBAL_EnableMicrosoftCodeAnalysis true
        VS_GLOBAL_EnableClangTidyCodeAnalysis true
    )
endif()
