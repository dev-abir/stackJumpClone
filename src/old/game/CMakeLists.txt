include_directories(${CMAKE_CURRENT_SOURCE_DIR}
					${CMAKE_CURRENT_SOURCE_DIR}/MainMenu
					${CMAKE_CURRENT_SOURCE_DIR}/Misc
					${CMAKE_CURRENT_SOURCE_DIR}/NewGame)

add_executable(game
					${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
					${CMAKE_CURRENT_SOURCE_DIR}/MainMenu/MainMenu.cpp
					${CMAKE_CURRENT_SOURCE_DIR}/NewGame/NewGame.cpp
					${CMAKE_CURRENT_SOURCE_DIR}/PauseMenu/PauseMenu.cpp)

target_link_libraries(game StackJumpCloneEngine sfml-graphics sfml-window sfml-system)
