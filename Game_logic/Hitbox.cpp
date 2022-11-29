//
// Created by jarne on 11/19/22.
//

#include "Hitbox.h"
#include <math.h>
#include <iostream>


// use shortest distance to find
/*bool Hitbox::collides(const Hitbox &other) const {
    double x_dist = std::abs(other.left_side - left_side);
    double y_dist = std::abs(other.top_side - top_side);

    double x_min_dist = (other.w + w) / 2;
    double y_min_dist = (other.h + h) / 2;

    return x_dist < x_min_dist && y_dist < y_min_dist;
}*/


bool Hitbox::collides(const Hitbox &other) const {
    if (right_side > other.left_side && left_side < other.right_side) {
        if (top_side < other.bottom_side && bottom_side > other.top_side) {
            return true;
        }
    }
    return false;
}


bool Hitbox::collides_left_side(const Hitbox &other) const {
if (left_side < other.right_side && left_side > other.left_side) {
        if (top_side < other.bottom_side && bottom_side > other.top_side) {
            return true;
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
    if (left_side < other.right_side && right_side > other.right_side) {
        if (top_side < other.bottom_side && bottom_side > other.top_side) {
            return true;
        }
    }
    return false;
}

bool Hitbox::collides_top_side(const Hitbox &other) const {
    if (bottom_side >= other.top_side && top_side <= other.top_side) {
        if (left_side < other.right_side && right_side > other.left_side) {
            return true;
        }
    }
    return false;
}

bool Hitbox::collides_bottom_side(const Hitbox &other) const {
    if (top_side < other.bottom_side && bottom_side > other.bottom_side) {
        if (left_side < other.right_side && right_side > other.left_side) {
            return true;
        }
    }
    return false;
}

int Hitbox::get_top() const {
    return top_side;
}

int Hitbox::get_bottom() const {
    return bottom_side;
}

int Hitbox::get_left() const {
    return left_side;
}

int Hitbox::get_right() const {
    return right_side;
}
