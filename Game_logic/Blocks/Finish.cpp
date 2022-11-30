//
// Created by jarne on 11/30/22.
//

#include "Finish.h"

Finish::Finish(int x, int y, int width, int height) : Entity(x, y, width, height) {
    block_type = Block_type::FINISH;
}

Block_type Finish::get_type() const {
    return Block_type::FINISH;
}

Hitbox Finish::get_hitbox() const {
    return Hitbox(x, y, width, height);
}

