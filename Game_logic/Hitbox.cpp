//
// Created by jarne on 11/19/22.
//

#include "Hitbox.h"

bool Hitbox::collides(const Hitbox &other) const {
    if (right_side > other.left_side && left_side < other.right_side) {
        if (top_side < other.bottom_side && bottom_side > other.top_side) {
            return true;
        }
    }
    return false;
}

// todo: this sucks
bool Hitbox::collides_left_side(const Hitbox &other) const {
    if (right_side > other.left_side && left_side < other.right_side) {
        if (top_side < other.bottom_side && bottom_side > other.top_side) {
            if (right_side - other.left_side < 5) {
                return true;
            }
        }
    }
    return false;
}



Hitbox::Hitbox(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {
    left_side = x;
    right_side = x + w;
    top_side = y;
    bottom_side = y + h;
}

bool Hitbox::collides_right_side(const Hitbox &other) const {
    if (left_side < other.right_side && right_side > other.left_side) {
        if (top_side < other.bottom_side && bottom_side > other.top_side) {
            if (other.right_side - left_side < 5) {
                return true;
            }
        }
    }
    return false;
}

bool Hitbox::collides_top_side(const Hitbox &other) const {
    if (bottom_side > other.top_side && top_side < other.bottom_side) {
        if (left_side < other.right_side && right_side > other.left_side) {
            if (bottom_side - other.top_side < 5) {
                return true;
            }
        }
    }
    return false;
}

bool Hitbox::collides_bottom_side(const Hitbox &other) const {
    if (top_side < other.bottom_side && bottom_side > other.top_side) {
        if (left_side < other.right_side && right_side > other.left_side) {
            if (other.bottom_side - top_side < 5) {
                return true;
            }
        }
    }
    return false;
}
