//
// Created by jarne on 11/15/22.
//

#include "Entity.h"

Entity::Entity(int x, int y, int width, int height): x(x), y(y), width(width), height(height) {}

GrassBlock::GrassBlock(int x, int y, int width, int height) : Entity(x, y, width, height) {
    block_type = Block_type::GRASS;
}

DirtBlock::DirtBlock(int x, int y, int width, int height) : Entity(x, y, width, height) {
    block_type = Block_type::DIRT;
}
