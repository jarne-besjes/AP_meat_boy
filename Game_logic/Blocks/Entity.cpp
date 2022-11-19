//
// Created by jarne on 11/15/22.
//

#include "Entity.h"

Entity::Entity(int x, int y, int width, int height): x(x), y(y), width(width), height(height) {}

int Entity::get_x() const {
    return x;
}

int Entity::get_y() const {
    return y;
}

int Entity::get_width() const {
    return width;
}

int Entity::get_height() const {
    return height;
}


GrassBlock::GrassBlock(int x, int y, int width, int height) : Entity(x, y, width, height) {
    block_type = Block_type::GRASS;
}

Block_type GrassBlock::get_type() const {
    return Block_type::GRASS;
}

Hitbox GrassBlock::get_hitbox() const {
    return Hitbox(x,y, width, height);
}

DirtBlock::DirtBlock(int x, int y, int width, int height) : Entity(x, y, width, height) {
    block_type = Block_type::DIRT;
}

Block_type DirtBlock::get_type() const {
    return Block_type::DIRT;
}

Hitbox DirtBlock::get_hitbox() const {
    return Hitbox(x, y, width, height);
}
