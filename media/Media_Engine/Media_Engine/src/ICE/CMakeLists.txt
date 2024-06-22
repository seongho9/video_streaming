add_library(SDP "SDP.cpp" "Media.cpp" "Attribute.cpp" "Origin.cpp")

target_include_directories(SDP PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})