cmake_minimum_required(VERSION  3.2 )

project( duffel )

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package( Boost COMPONENTS system  REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

find_package ( cppnetlib 0.11 REQUIRED )
include_directories ( ${CPPNETLIB_INCLUDE_DIRS} )
include_directories( include )

add_definitions(-std=c++11)
add_executable( chat_pp_server  src/main.cpp)

target_link_libraries( chat_pp_server ${CPPNETLIB_LIBRARIES} )
TARGET_LINK_LIBRARIES( chat_pp_server ${Boost_LIBRARIES} )
target_link_libraries( chat_pp_server Threads::Threads)
