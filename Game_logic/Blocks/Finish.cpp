//
// Created by jarne on 11/30/22.
//

#include "Finish.h"

namespace Game_logic {

/**
 * @brief Construct a new Finish:: Finish object
 *
 * @param x : x coordinate of the finish
 * @param y : y coordinate of the finish
 * @param width : width of the finish
 * @param height : height of the finish
 */
    Finish::Finish(int x, int y, int width, int height) : Entity(x, y, width, height) {
        block_type = Block_type::FINISH;
    }

/**
 * @brief Return the type of the block
 *
 * @return Block_type : type of the block
 */
    Block_type Finish::get_type() const {
        return Block_type::FINISH;
    }

/**
 * @brief Return the hitbox of the finish
 *
 * @return Hitbox : hitbox of the finish
 */
    Game_logic::Hitbox Finish::get_hitbox() const {
        return {x, y, width, height};
    }

}

