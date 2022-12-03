//
// Created by jarne on 11/13/22.
//

#include "Player.h"
#include <math.h>
#include <iostream>
#include "Hitbox.h"
#include "../Values.cpp"


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

    if (position_x < 0) {
        position_x = 0;
    } else if (position_x > WINDOW_WIDTH - SPRITEWIDTH) {
        position_x = WINDOW_WIDTH - SPRITEWIDTH;
    }
    if (position_y > WINDOW_HEIGHT - SPRITEHEIGHT) {
        position_y = WINDOW_HEIGHT - SPRITEHEIGHT;
        velocity_y = 0;
    } else if (position_y < 0) {
        position_y = 0;
    }


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



Position Player::get_position() {
    return Position{position_x, position_y};
}

Hitbox Player::get_hitbox() {
    return Hitbox{position_x, position_y, SPRITEWIDTH, SPRITEHEIGHT};
}

Player::Player() {
    position_x = 100;
    position_y = 100;
    velocity_x = 0;
    velocity_y = 0;

}

void Player::set_position(double x, double y) {
    position_x = x;
    position_y = y;

}

void Player::reset() {
    position_x = 100;
    position_y = 100;
    velocity_x = 0;
    velocity_y = 0;
    collided_with_finish = false;
    on_ground = false;
}
