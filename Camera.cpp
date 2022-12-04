//
// Created by jarne on 11/21/22.
//

#include "Camera.h"
/**
 * @brief Returns the x coordinate of the camera
 * 
 * @return int : x coordinate
 */
int Camera::get_x() const {
    return x;
}

/**
 * @brief Returns the y coordinate of the camera
 * 
 * @return int : y coordinate
 */
int Camera::get_y() const {
    return y;
}

/**
 * @brief Returns the width of the camera (the width of the visible part of the screen)
 * 
 * @return int : width
 */
int Camera::get_width() const {
    return width;
}

/**
 * @brief Returns the height of the camera (the height of the visible part of the screen)
 * 
 * @return int : height
 */
int Camera::get_height() const {
    return height;
}

/**
 * @brief sets the y coordinate of the camera
 * 
 * @param _y : y coordinate
 */
void Camera::set_y(int _y) {
    Camera::y = _y;
}

/**
 * @brief moves the camera up by `amount` pixels
 * 
 * @param amount : amount of pixels to move the camera up
 */
void Camera::move_up(int amount) {
    y -= amount;
}

/**
 * @brief Set the level height, so that we can start the camera all the way down
 *        You always have to do this before you start using the camera
 * 
 * @param level_y_size : the vertical level size
 */
void Camera::set_level_size(int level_y_size) {
    y = level_y_size * 50 - 300;
}

/**
 * @brief Construct a new Camera:: Camera object
 * 
 */
Camera::Camera() {
    y = 0;
}


