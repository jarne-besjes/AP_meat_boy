//
// Created by jarne on 11/13/22.
//

#include "Player.h"
#include <math.h>
#include <iostream>
#include "Hitbox.h"
#include "../Values.cpp"
#include "../Stopwatch.h"

namespace Game_logic {

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

        double elapsed_time = Stopwatch::getInstance()->elapsed();

        if (up) {
            if (on_ground) {
                velocity_y = -JUMP_ACCEL;
                on_ground = false;
            } else if (against_wall) {
                velocity_y = -JUMP_ACCEL;
                velocity_x = against_wall_left ? PLAYER_ACCELERATION * 15 : -PLAYER_ACCELERATION * 15;
                against_wall = false;
            }
        }

        if (!on_ground) {
            if (!against_wall) {
                velocity_y += GRAVITY;
            } else {
                velocity_y += GRAVITY / 4;
                if (velocity_y > PLAYER_MAX_SPEED / 2) {
                    velocity_y = PLAYER_MAX_SPEED / 2;
                }
            }
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
            } else if (velocity_x < 0) {
                velocity_x += PLAYER_DECELERATION;
                if (velocity_x > 0) {
                    velocity_x = 0;
                }
            }
        }


        position_x += velocity_x * elapsed_time * global_time_scale;
        position_y += velocity_y * elapsed_time * global_time_scale;

        // check hitboxes
        bool collided = false;
        bool collided_with_teleporter = false;
        if (teleporter_counter_active) {
            teleporter_counter++;
            if (teleporter_counter > 300) {
                teleporter_counter_active = false;
                teleporter_counter = 0;
            }
        }
        for (auto &entity: entities) {
            if (this->get_hitbox().collides(entity->get_hitbox())) {
                if (entity->get_type() == Block_type::FINISH) {
                    collided_with_finish = true;
                } else if (entity->get_type() == Block_type::SAW) {
                    collided_with_deadly_object = true;
                } else if (entity->get_type() == Block_type::TELEPORTER && !teleporter_counter_active) {
                    collided_with_teleporter = true;
                    teleporter_counter_active = true;
                    for (auto &other_entity : entities) {
                        if (other_entity->get_type() == Block_type::TELEPORTER && other_entity != entity) {
                            collided_teleporter = other_entity.get();
                        }
                    }
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
                        against_wall = true;
                        if (velocity_x > 0) {
                            position_x = entity->get_x() - SPRITEWIDTH;
                            against_wall_left = false;
                        } else if (velocity_x < 0) {
                            position_x = entity->get_x() + SPRITEWIDTH;
                            against_wall_left = true;
                        }
                        velocity_x = 0;
                    } else {
                        // vertical
                        against_wall = false;
                        if (velocity_y > 0) {
                            position_y = entity->get_y() - SPRITEHEIGHT;
                            on_ground = true;
                        } else if (velocity_y < 0) {
                            position_y = entity->get_y() + SPRITEHEIGHT + 0.1f;
                        }
                        velocity_y = 0;
                    }
                }
                if (!collided_with_teleporter) collided_teleporter = nullptr;
            }
        }

        if (!collided) {
            against_wall = false;
            on_ground = false;
        }

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
        collided_teleporter = nullptr;
        teleporter_counter_active = false;
        teleporter_counter = 0;
        against_wall = false;
        against_wall_left = false;
        collided_with_deadly_object = false;
    }

    Position Player::get_projected_position() {
        return Position{projected_x, projected_y};
    }

}