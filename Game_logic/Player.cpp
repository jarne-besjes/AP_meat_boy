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
    } else {
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
    for(auto &entity : entities) {
        if (this->get_hitbox().collides(entity->get_hitbox())) {
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



        /*if (this->get_hitbox().collides_left_side(entity->get_hitbox())) {
            position_x = entity->get_hitbox().left_side - SPRITEWIDTH;
            velocity_x = 0;
        }
        if (this->get_hitbox().collides_right_side(entity->get_hitbox())) {
            position_x = entity->get_hitbox().left_side + SPRITEWIDTH;
            velocity_x = 0;
        }
        if (this->get_hitbox().collides_top_side(entity->get_hitbox())) {
            position_y = entity->get_hitbox().top_side - SPRITEHEIGHT;
            velocity_y = 0;
            on_ground = true;
        }
        if (this->get_hitbox().collides_bottom_side(entity->get_hitbox())) {
            position_y = entity->get_hitbox().top_side + SPRITEHEIGHT;
            velocity_y = 0;
        }*/
    }



    notify_observers();

}

void Player::key_pressed(bool left, bool right, bool down, bool up) {
    // TODO: check how velocity_y is update, this is always .2 now

    /*
    if (up  && std::abs(velocity_y) <= 0.2) {
        std::cout << "jump; velocity y: " << velocity_y << std::endl;
        velocity_y -= JUMP_ACCEL;
        if (velocity_y < -PLAYER_MAX_SPEED) {
            velocity_y = -PLAYER_MAX_SPEED;
        }
    }/*
    if (down) {
        velocity_y += PLAYER_ACCELERATION;
        if (velocity_y > PLAYER_MAX_SPEED) {
            velocity_y = PLAYER_MAX_SPEED;
        }
    }
    if (right) {
        velocity_x += PLAYER_ACCELERATION;
        if (velocity_x > PLAYER_MAX_SPEED) {
            velocity_x = PLAYER_MAX_SPEED;
        }
    }
    if (left) {
        velocity_x -= PLAYER_ACCELERATION;
        if (velocity_x < -PLAYER_MAX_SPEED) {
            velocity_x = -PLAYER_MAX_SPEED;
        }
    }
    */
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
