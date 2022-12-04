//
// Created by jarne on 11/17/22.
//

#include "Entity_factory.h"
#include "Entity.h"
#include "Finish.h"
/**
 * @brief Creates and returns a grass entity
 * 
 * @param x : x coordinate of the entity
 * @param y : y coordinate of the entity
 * @param width : width of the entity
 * @param height : height of the entity
 * 
 * @return std::unique_ptr<Entity> : the created entity
 */
std::unique_ptr<Entity> Grass_factory::create_entity(int x, int y, int width, int height) {
    return std::make_unique<GrassBlock>(x, y, width, height);
}

/**
 * @brief Creates and returns a dirt entity
 * 
 * @param x : x coordinate of the entity
 * @param y : y coordinate of the entity
 * @param width : width of the entity
 * @param height : height of the entity
 * 
 * @return std::unique_ptr<Entity> : the created entity
 */
std::unique_ptr<Entity> Dirt_factory::create_entity(int x, int y, int width, int height) {
    return std::make_unique<DirtBlock>(x, y, width, height);
}

/**
 * @brief Destroy the Entity_factory::Entity_factory object
 * 
 */
Entity_factory::~Entity_factory() {}

/**
 * @brief Creates and returns a finish entity
 * 
 * @param x : x coordinate of the entity
 * @param y : y coordinate of the entity
 * @param width : width of the entity
 * @param height : height of the entity
 * 
 * @return std::unique_ptr<Entity> : the created entity
 */
std::unique_ptr<Entity> Finish_factory::create_entity(int x, int y, int width, int height) {
    return std::make_unique<Finish>(x,y, width, height);
}
