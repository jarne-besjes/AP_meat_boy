//
// Created by jarne on 11/15/22.
//

#include "Entity.h"
/**
 * @brief Construct a new Entity:: Entity object
 * 
 * @param x : x coordinate of the entity
 * @param y : y coordinate of the entity
 * @param width : width of the entity
 * @param height : height of the entity
 */
Entity::Entity(int x, int y, int width, int height): x(x), y(y), width(width), height(height) {}

/**
 * @brief return the x coordinate of the entity
 * 
 * @return int : x coordinate of the entity
 */
int Entity::get_x() const {
    return x;
}

/**
 * @brief return the y coordinate of the entity
 * 
 * @return int : y coordinate of the entity
 */
int Entity::get_y() const {
    return y;
}

/**
 * @brief return the width of the entity
 * 
 * @return int : width of the entity
 */
int Entity::get_width() const {
    return width;
}

/**
 * @brief return the height of the entity
 * 
 * @return int : height of the entity
 */
int Entity::get_height() const {
    return height;
}

/**
 * @brief set the position of the entity
 * 
 * @param x : x coordinate of the entity
 * @param y : y coordinate of the entity
 */
void Entity::set_position(int x, int y) {
    this->x = x;
    this->y = y;
}

/**
 * @brief Construct a new Grass Block:: Grass Block object
 * 
 * @param x : x coordinate of the grass block
 * @param y : y coordinate of the grass block
 * @param width : width of the grass block
 * @param height : height of the grass block
 */
GrassBlock::GrassBlock(int x, int y, int width, int height) : Entity(x, y, width, height) {
    block_type = Block_type::GRASS;
}

/**
 * @brief Return the type of the block
 * 
 * @return Block_type : type of the block
 */
Block_type GrassBlock::get_type() const {
    return Block_type::GRASS;
}

/**
 * @brief Return the hitbox of the grass block
 * 
 * @return Hitbox : hitbox of the grass block
 */
Hitbox GrassBlock::get_hitbox() const {
    return Hitbox(x,y, width, height);
}

/**
 * @brief Construct a new Dirt Block:: Dirt Block object
 * 
 * @param x : x coordinate of the dirt block
 * @param y : y coordinate of the dirt block
 * @param width : width of the dirt block
 * @param height : height of the dirt block
 */
DirtBlock::DirtBlock(int x, int y, int width, int height) : Entity(x, y, width, height) {
    block_type = Block_type::DIRT;
}

/**
 * @brief Return the type of the block
 * 
 * @return Block_type : type of the block
 */
Block_type DirtBlock::get_type() const {
    return Block_type::DIRT;
}

/**
 * @brief Return the hitbox of the dirt block
 * 
 * @return Hitbox : hitbox of the dirt block
 */
Hitbox DirtBlock::get_hitbox() const {
    return Hitbox(x, y, width, height);
}
