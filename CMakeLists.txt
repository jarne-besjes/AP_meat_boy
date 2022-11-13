CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
PROJECT(meat_boy)
IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF()


# The source files to compile
SET(SRC main.cpp)

include_directories(Game_representation)
include_directories(Game_logic)

add_subdirectory(Game_representation)
add_subdirectory(Game_logic)

# The program we're compiling with the sources set above
ADD_EXECUTABLE(meat_boy ${SRC})

TARGET_LINK_LIBRARIES(meat_boy Meat_boy_game_representation Meat_boy_game_logic)


# Install our executable to the CMAKE_INSTALL_PREFIX/bin
INSTALL(TARGETS meat_boy DESTINATION bin)