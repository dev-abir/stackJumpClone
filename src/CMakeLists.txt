
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

include_directories(${stackJumpClone_SOURCE_DIR}
                    ${stackJumpClone_SOURCE_DIR}/MainMenu
                    ${stackJumpClone_SOURCE_DIR}/Misc
                    ${stackJumpClone_SOURCE_DIR}/NewGame)

file(GLOB all_sources 
                    "${stackJumpClone_SOURCE_DIR}/*.cpp"
                    "${stackJumpClone_SOURCE_DIR}/MainMenu/*.cpp"
                    "${stackJumpClone_SOURCE_DIR}/PauseMenu/*.cpp"
                    "${stackJumpClone_SOURCE_DIR}/Misc/*.cpp"
                    "${stackJumpClone_SOURCE_DIR}/NewGame/*.cpp")

add_library(StackJumpClone ${all_sources})

add_executable(game main.cpp)

target_link_libraries(game StackJumpClone sfml-graphics sfml-window sfml-system)
