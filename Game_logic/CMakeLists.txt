CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
PROJECT(Meat_boy_game_logic)
IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF()

# The source files to compile
SET(SRC World.cpp Player.cpp Player.h Blocks/Block.cpp Blocks/Block.h Entity.cpp Entity.h)

# The program we're compiling with the sources set above
ADD_LIBRARY(Meat_boy_game_logic ${SRC})

TARGET_LINK_LIBRARIES(Meat_boy_game_representation)