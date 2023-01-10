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
                velocity_y += GRAVITY * elapsed_time * global_time_scale;
            } else {
                velocity_y += GRAVITY / 1.5 * elapsed_time * global_time_scale;
                if (velocity_y > PLAYER_MAX_SPEED / 2) {
                    velocity_y = PLAYER_MAX_SPEED / 2;
                }
            }
        }

        if (velocity_y > PLAYER_MAX_SPEED * 2) {
            velocity_y = PLAYER_MAX_SPEED * 2;
        }

        if (right) {
            velocity_x += PLAYER_ACCELERATION * elapsed_time * global_time_scale;
        } else if (left) {
            velocity_x -= PLAYER_ACCELERATION * elapsed_time * global_time_scale;
        } else {
            if (velocity_x > 0) {
                velocity_x -= PLAYER_DECELERATION * elapsed_time * global_time_scale;
                if (velocity_x < 0) {
                    velocity_x = 0;
                }
            } else if (velocity_x < 0) {
                velocity_x += PLAYER_DECELERATION * elapsed_time * global_time_scale;
                if (velocity_x > 0) {
                    velocity_x = 0;
                }
            }
        }

        double wanted_x = position_x + velocity_x * elapsed_time * global_time_scale;
        double wanted_y = position_y + velocity_y * elapsed_time * global_time_scale;
        double collision_time;
        if (!against_wall || !on_ground) {
            collision_time = check_sweeping_collision(wanted_x, wanted_y, entities);
        } else {
            collision_time = 1.0f;
        }

        position_x += velocity_x * collision_time * elapsed_time * global_time_scale;
        position_y += velocity_y * collision_time * elapsed_time * global_time_scale;

        bool collided = collision_time != 1.0f;

        // check hitboxes
        bool collided_with_teleporter = false;
        if (teleporter_counter_active) {
            teleporter_counter++;
            if (teleporter_counter > 300) {
                teleporter_counter_active = false;
                teleporter_counter = 0;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            std::cout << std::endl;
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
                    // reset player speed
                    velocity_x = 0;
                    velocity_y = 0;
                    for (auto &other_entity: entities) {
                        if (other_entity->get_type() == Block_type::TELEPORTER && other_entity != entity) {
                            collided_teleporter = other_entity.get();
                        }
                    }
                } else {
                    collided = true;
                    double shortest_x;
                    double shortest_y;

                    shortest_x = std::min(std::abs(entity->get_hitbox().get_left() - this->get_hitbox().get_right()),
                                          std::abs(entity->get_hitbox().get_right() - this->get_hitbox().get_left()));

                    shortest_y = std::min(std::abs(this->get_hitbox().get_top() - entity->get_hitbox().get_bottom()),
                                          std::abs(this->get_hitbox().get_bottom() - entity->get_hitbox().get_top()));

                    double shortest_x_vel =
                            velocity_x > 0 ? std::abs(this->get_hitbox().get_right() - entity->get_hitbox().get_left())
                                           : std::abs(this->get_hitbox().get_left() - entity->get_hitbox().get_right());

                    double shortest_y_vel =
                            velocity_y > 0 ? std::abs(this->get_hitbox().get_bottom() - entity->get_hitbox().get_top())
                                           : std::abs(this->get_hitbox().get_top() - entity->get_hitbox().get_bottom());


                    if (shortest_x <= shortest_y) {
                        if (shortest_x != shortest_x_vel) continue;
                        //horizontal
                        against_wall = true;
                        if (velocity_x > 0) {
                            position_x = entity->get_x() - SPRITEWIDTH + 0.1f;
                            against_wall_left = false;
                        } else if (velocity_x < 0) {
                            position_x = entity->get_x() + SPRITEWIDTH - 0.1f;
                            against_wall_left = true;
                        }
                        velocity_x = 0;
                        on_ground = false;
                    } else {
                        if (shortest_y != shortest_y_vel) continue;
                        // vertical
                        against_wall = false;
                        if (velocity_y > 0) {
                            position_y = entity->get_y() - SPRITEHEIGHT + 0.1f;
                            on_ground = true;
                        } else if (velocity_y < 0) {
                            position_y = entity->get_y() + SPRITEHEIGHT - 0.1f;
                        }
                        velocity_y = velocity_y == 0 ? GRAVITY : 0;
                    }
                }
                if (!collided_with_teleporter) collided_teleporter = nullptr;
            }
        }

        if (position_x < 0) {
            collided_with_deadly_object = true;
            position_x = 0;
        } else if (position_x > WINDOW_WIDTH - SPRITEWIDTH) {
            position_x = WINDOW_WIDTH - SPRITEWIDTH;
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

    /**
     * @brief return the projected position of the player
     * @return : projected position of the player
     */
    Position Player::get_projected_position() {
        return Position{projected_x, projected_y};
    }

    // used a source in this case to get sweeping collision detection working
    // https://www.amanotes.com/post/using-swept-aabb-to-detect-and-process-collision
    /**
     * @brief check if the player collides with an entity by sweeping the hitbox
     * @param wanted_x : x coordinate of the position the player wants to go to
     * @param wanted_y : y coordinate of the position the player wants to go to
     * @param entities : vector of entities in the world
     * @return : time of collision
     */
    double Player::check_sweeping_collision(double &wanted_x, double &wanted_y,
                                            std::vector<std::shared_ptr<Entity>> &entities) const {
        double dxEntry, dyEntry, dxExit, dyExit, txEntry, tyEntry, txExit, tyExit;
        dxEntry = std::numeric_limits<double>::infinity();
        dyEntry = std::numeric_limits<double>::infinity();
        dxExit = std::numeric_limits<double>::infinity();
        dyExit = std::numeric_limits<double>::infinity();
        for (const auto &entity: entities) {
            if (velocity_x > 0) {
                // distance we have to move to begin contact with entity
                dxEntry = std::min(dxEntry, entity->get_hitbox().get_left() - (position_x + SPRITEWIDTH));
                // distance we have to move to end contact with entity
                dxExit = std::min(dxExit, entity->get_hitbox().get_right() - position_x);
            } else {
                dxEntry = std::min(dxEntry, entity->get_hitbox().get_right() - position_x);
                dxExit = std::min(dxExit, entity->get_hitbox().get_left() - (position_x + SPRITEWIDTH));
            }

            if (velocity_y > 0) {
                dyEntry = std::min(dyEntry, entity->get_hitbox().get_top() - (position_y + SPRITEHEIGHT));
                dyExit = std::min(dyExit, entity->get_hitbox().get_bottom() - position_y);
            } else {
                dyEntry = std::min(dyEntry, entity->get_hitbox().get_bottom() - position_y);
                dyExit = std::min(dyExit, entity->get_hitbox().get_top() - (position_y + SPRITEHEIGHT));
            }

        }

        if (velocity_x == 0) {
            txEntry = -std::numeric_limits<double>::infinity();
            txExit = std::numeric_limits<double>::infinity();
        } else {
            txEntry = dxEntry / velocity_x;
            txExit = dxExit / velocity_x;
        }

        if (velocity_y == 0) {
            tyEntry = -std::numeric_limits<double>::infinity();
            tyExit = std::numeric_limits<double>::infinity();
        } else {
            tyEntry = dyEntry / velocity_y;
            tyExit = dyExit / velocity_y;
        }


        double entryTime = std::max(txEntry, tyEntry);
        double exitTime = std::min(txExit, tyExit);

        if (entryTime > exitTime || (txEntry < 0 && tyEntry < 0) || txEntry > 1 || tyEntry > 1 || txEntry == 0 ||
            tyEntry == 0) {
            return 1;
        }

        return entryTime;
    }

}