//
// Created by jarne on 11/17/22.
//

#include "Entity_factory.h"
#include "Entity.h"

std::unique_ptr<Entity> Grass_factory::create_entity(int x, int y, int width, int height) {
    return std::make_unique<GrassBlock>(x, y, width, height);
}

std::unique_ptr<Entity> Dirt_factory::create_entity(int x, int y, int width, int height) {
    return std::make_unique<DirtBlock>(x, y, width, height);
}
