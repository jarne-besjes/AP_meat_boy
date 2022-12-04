//
// Created by jarne on 11/13/22.
//

#include "Player.h"
#include <math.h>
#include <iostream>
#include "Hitbox.h"
#include "../Values.cpp"

/**
 * @brief Update the player object
 * 
 * @param left : if the left key is pressed
 * @param right : if the right key is pressed
 * @param down : if the down key is pressed
 * @param up : if the up key is pressed
 * @param entities : vector of entities in the world the player is in
 */
void Player::update(bool left, bool right, bool down, bool up, std::vector<std::shared_ptr<Entity>> &entities) {

    if (up && on_ground) {
        on_ground = false;
        velocity_y -= JUMP_ACCEL;
    } else if (!on_ground){
        velocity_y += GRAVITY;
    }

    if (velocity_y > PLAYER_MAX_SPEED) {
        velocity_y = PLAYER_MAX_SPEED;
    }

    if (right) {
        velocity_x += PLAYER_ACCELERATION;
    } else if (left) {
        velocity_x -= PLAYER_ACCELERATION;
    } else {
        if (velocity_x > 0) {
            velocity_x -= PLAYER_DECELERATION;
            if (velocity_x < 0) {
                velocity_x = 0;
            }
        } else if (velocity_x < 0 && !on_ground) {
            velocity_x += PLAYER_DECELERATION;
            if (velocity_x > 0) {
                velocity_x = 0;
            }
        }
    }


    position_x += velocity_x;
    position_y += velocity_y;

    // check hitboxes
    bool collided = false;
    for(auto &entity : entities) {
        if (this->get_hitbox().collides(entity->get_hitbox())) {
            if (entity->get_type() == Block_type::FINISH) {
                collided_with_finish = true;
            } else {
                collided = true;
                double shortest_x;
                double shortest_y;
                shortest_x = std::min(std::abs(this->get_hitbox().get_right() - entity->get_hitbox().get_left()),
                                      std::abs(this->get_hitbox().get_left() - entity->get_hitbox().get_right()));
                shortest_y = std::min(std::abs(this->get_hitbox().get_top() - entity->get_hitbox().get_bottom()),
                                      std::abs(this->get_hitbox().get_bottom() - entity->get_hitbox().get_top()));

                if (shortest_x <= shortest_y) {
                    //horizontal
                    if (velocity_x > 0) {
                        position_x = entity->get_x() - SPRITEWIDTH;
                    } else if (velocity_x < 0) {
                        position_x = entity->get_x() + SPRITEWIDTH;
                    }
                    velocity_x = 0;
                } else {
                    // vertical
                    if (velocity_y > 0) {
                        position_y = entity->get_y() - SPRITEHEIGHT;
                        on_ground = true;
                    } else if (velocity_y < 0) {
                        position_y = entity->get_y() + SPRITEHEIGHT;
                    }
                    velocity_y = 0;
                }
            }
        }
    }

    if (!collided) on_ground = false;

    notify_observers();

}

/**
 * @brief Returns the position of the player
 * 
 * @return Position : position of the player
 */
Position Player::get_position() {
    return Position{position_x, position_y};
}

/**
 * @brief Returns the hitbox of the player
 * 
 * @return Hitbox : hitbox of the player
 */
Hitbox Player::get_hitbox() {
    return Hitbox{position_x, position_y, SPRITEWIDTH, SPRITEHEIGHT};
}

/**
 * @brief Construct a new Player:: Player object
 * 
 */
Player::Player() {
    position_x = 100;
    position_y = 100;
    velocity_x = 0;
    velocity_y = 0;

}

/**
 * @brief set the position of the player
 * 
 * @param x : x coordinate of the player
 * @param y : y coordinate of the player
 */
void Player::set_position(double x, double y) {
    position_x = x;
    position_y = y;

}

/**
 * @brief Reset the player
 * 
 */
void Player::reset() {
    position_x = 100;
    position_y = 100;
    velocity_x = 0;
    velocity_y = 0;
    collided_with_finish = false;
    on_ground = false;
}
