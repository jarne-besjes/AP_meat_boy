//
// Created by jarne on 11/21/22.
//

#include "Camera.h"
#include <iostream>

/**
 * @brief Returns the x coordinate of the camera
 * 
 * @return int : x coordinate
 */
float Camera::get_x() const {
    return x;
}

/**
 * @brief Returns the y coordinate of the camera
 * 
 * @return int : y coordinate
 */
float Camera::get_y() const {
    return y;
}

/**
 * @brief Returns the width of the camera (the width of the visible part of the screen)
 * 
 * @return int : width
 */
float Camera::get_width() const {
    return width;
}

/**
 * @brief Returns the height of the camera (the height of the visible part of the screen)
 * 
 * @return int : height
 */
float Camera::get_height() const {
    return height;
}

/**
 * @brief sets the y coordinate of the camera
 * 
 * @param _y : y coordinate
 */
void Camera::set_y(float _y) {
    Camera::y = _y;
    bottom_y = y - WINDOW_HEIGHT / 2;
    top_y = y + WINDOW_HEIGHT / 2;
}

/**
 * @brief moves the camera up by `amount` pixels
 * 
 * @param amount : amount of pixels to move the camera up
 */
void Camera::move_up(float amount) {
    y -= amount;
    bottom_y = y - WINDOW_HEIGHT / 2;
    top_y = y + WINDOW_HEIGHT / 2;
}

/**
 * @brief Set the level height, so that we can start the camera all the way down
 *        You always have to do this before you start using the camera
 * 
 * @param level_y_size : the vertical level size
 */
void Camera::set_level_size(int level_y_size) {
    y = level_y_size * 50 - 300;
    bottom_y = y - WINDOW_HEIGHT / 2;
    top_y = y + WINDOW_HEIGHT / 2;
}

/**
 * @brief Construct a new Camera:: Camera object
 * 
 */
Camera::Camera() {
    y = 0;
}

void Camera::get_visible_entities(std::vector<std::shared_ptr<Game_logic::Entity>> &entities) const {
    for (auto &entity: entities) {
        if (entity->get_y() > bottom_y - 50 && entity->get_y() < top_y + 50) {
            entity->visible = true;
        }
    }
}

void Camera::clear_visible_entities(std::vector<std::shared_ptr<Game_logic::Entity>> &entities) {
    for (auto &entity: entities) {
        entity->visible = false;
    }
}

void Camera::project_entities(std::vector<std::shared_ptr<Game_logic::Entity>> &entities) {
    for (auto &entity: entities) {
        if (entity->visible) {
            entity->projected_x = entity->get_x();
            entity->projected_y = WINDOW_HEIGHT - (top_y - entity->get_y());
        }
    }
}

void Camera::project_player(Game_logic::Player &player) const {
    Game_logic::Position playerpos = player.get_position();
    player.projected_x = playerpos.x;
    player.projected_y = WINDOW_HEIGHT - (top_y - playerpos.y);
}

