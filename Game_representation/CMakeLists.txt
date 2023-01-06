CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
PROJECT(Meat_boy_game_representation)
IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF()

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile
SET(SRC Game.cpp Main_menu.cpp View.cpp View.h State.cpp Level_selection.cpp Finished_menu.cpp Dead_menu.cpp Dead_menu.h Menu.cpp Menu.h)

# Add include dirs for SFML
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_LIBRARY(Meat_boy_game_representation ${SRC})

# Link target to SFML libs
TARGET_LINK_LIBRARIES(Meat_boy_game_representation sfml-system sfml-graphics sfml-window)