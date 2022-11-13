//
// Created by jarne on 11/13/22.
//

#include "World.h"

void World::load_level(std::string level_name) {
    std::cout << "Loading level: " << level_name << std::endl;
}

Player &World::get_player() {
    return player;
}
