
###############################################################
#
#
#	This CMakeLists.txt file doesn't "find" the sfml libraries. Need to add "find sfml..."
#
#
###############################################################

cmake_minimum_required(VERSION 2.8)
project(stackJumpClone)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_VERBOSE_MAKEFILE ON)  #I like this
file(COPY ../resources DESTINATION ${CMAKE_BINARY_DIR})

add_subdirectory(engine)
add_subdirectory(game)
