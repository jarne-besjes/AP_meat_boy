//
// Created by jarne on 11/21/22.
//

#include "Camera.h"

int Camera::get_x() const {
    return x;
}

int Camera::get_y() const {
    return y;
}

int Camera::get_width() const {
    return width;
}

int Camera::get_height() const {
    return height;
}

void Camera::set_y(int _y) {
    Camera::y = _y;
}

void Camera::move_up(int amount) {
    y -= amount;
}

void Camera::set_level_size(int level_y_size) {
    y = level_y_size * 50 - 300;
}

Camera::Camera() {
    y = 0;
}


