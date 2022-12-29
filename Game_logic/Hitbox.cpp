//
// Created by jarne on 11/19/22.
//

#include "Hitbox.h"
#include <math.h>
#include <iostream>

namespace Game_logic {
    /**
 * @brief Check if the hitbox collides with another hitbox
 *
 * @param other : other hitbox
 * @return true : The hitboxes collide
 * @return false : The hitboxes don't collide
 */
    bool Hitbox::collides(const Hitbox &other) const {
        if (right_side > other.left_side && left_side < other.right_side) {
            if (top_side <= other.bottom_side && bottom_side >= other.top_side) {
                return true;
            }
        }
        return false;
    }

/**
 * @brief Check if the hitbox collides on the left side of the other hitbox
 *
 * @param other : other hitbox
 * @return true : The hitboxes collide on the left side
 * @return false : The hitboxes don't collide on the left side
 */
    bool Hitbox::collides_left_side(const Hitbox &other) const {
        if (left_side < other.right_side && left_side > other.left_side) {
            if (top_side < other.bottom_side && bottom_side > other.top_side) {
                return true;
            }
        }
        return false;
    }

/**
 * @brief Construct a new Hitbox:: Hitbox object
 *
 * @param x : x coordinate of the hitbox
 * @param y : y coordinate of the hitbox
 * @param w : width of the hitbox
 * @param h : height of the hitbox
 */
    Hitbox::Hitbox(double x, double y, double w, double h) : x(x), y(y), w(w), h(h) {
        left_side = x;
        right_side = x + w;
        top_side = y;
        bottom_side = y + h;
    }

/**
 * @brief check if the hitbox collides on the right side of the other hitbox
 *
 * @param other : other hitbox
 * @return true : The hitboxes collide on the right side
 * @return false : The hitboxes don't collide on the right side
 */
    bool Hitbox::collides_right_side(const Hitbox &other) const {
        if (left_side < other.right_side && right_side > other.right_side) {
            if (top_side < other.bottom_side && bottom_side > other.top_side) {
                return true;
            }
        }
        return false;
    }

/**
 * @brief check if the hitbox collides on the top side of the other hitbox
 *
 * @param other : other hitbox
 * @return true : The hitboxes collide on the top side
 * @return false : The hitboxes don't collide on the top side
 */
    bool Hitbox::collides_top_side(const Hitbox &other) const {
        if (bottom_side >= other.top_side && top_side <= other.top_side) {
            if (left_side < other.right_side && right_side > other.left_side) {
                return true;
            }
        }
        return false;
    }

/**
 * @brief check if the hitbox collides on the bottom side of the other hitbox
 *
 * @param other : other hitbox
 * @return true : The hitboxes collide on the bottom side
 * @return false : The hitboxes don't collide on the bottom side
 */
    bool Hitbox::collides_bottom_side(const Hitbox &other) const {
        if (top_side < other.bottom_side && bottom_side > other.bottom_side) {
            if (left_side < other.right_side && right_side > other.left_side) {
                return true;
            }
        }
        return false;
    }

/**
 * @brief Get the x coordinate of the hitbox
 *
 * @return int : x coordinate of the hitbox
 */
    double Hitbox::get_top() const {
        return top_side;
    }

/**
 * @brief Get the y coordinate of the bottom of the hitbox
 *
 * @return int : y coordinate of the bottom of the hitbox
 */
    double Hitbox::get_bottom() const {
        return bottom_side;
    }

/**
 * @brief Get the x coordinate of the left side of the hitbox
 *
 * @return int : x coordinate of the left side of the hitbox
 */
    double Hitbox::get_left() const {
        return left_side;
    }

/**
 * @brief Get the x coordinate of the right side of the hitbox
 *
 * @return int : x coordinate of the right side of the hitbox
 */
    double Hitbox::get_right() const {
        return right_side;
    }

}
