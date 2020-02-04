add_library(StackJumpCloneEngine
					${CMAKE_CURRENT_SOURCE_DIR}/GUI/TextBox.cpp
					${CMAKE_CURRENT_SOURCE_DIR}/Scene/Scene.cpp
					${CMAKE_CURRENT_SOURCE_DIR}/Util/Util.cpp)

target_include_directories(StackJumpCloneEngine
					PUBLIC					
					${CMAKE_CURRENT_SOURCE_DIR}
					${CMAKE_CURRENT_SOURCE_DIR}/GUI
					${CMAKE_CURRENT_SOURCE_DIR}/Scene
					${CMAKE_CURRENT_SOURCE_DIR}/Util)
