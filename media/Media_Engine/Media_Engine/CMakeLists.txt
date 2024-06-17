# ./CMakeLists.txt

# boost_library
set (BOOST_ROOT "C:\\Users\\SeonghoJang\\Desktop\\video_streaming\\media\\Media_Engine\\boost_1_84_0")
set (BOOST_LIBRARY_DIR "C:\\Users\\SeonghoJang\\Desktop\\video_streaming\\media\\Media_Engine\\boost_1_84_0\\stage\\lib")
set (BOOST_INCLUDE_DIR ${BOOST_ROOT})

include_directories(${BOOST_INCLUDE_DIR} include)
link_directories(${BOOST_LIBRARY_DIR})


add_subdirectory("./src")

add_executable (Media_Engine "Media_Engine.cpp" "Media_Engine.hpp")
target_link_libraries(${PROJECT_NAME} ${BOOST_LIBRARIES} WebSocket)

message("lo")
message(${CMAKE_SOURCE_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Media_Engine PROPERTY CXX_STANDARD 20)
endif()