//
// Created by jarne on 11/13/22.
//

#include "World.h"
#include "../include/json.hpp"
#include <fstream>
#include <iomanip>

using json = nlohmann::json;

void World::load_level(std::string level_name) {
    std::cout << "Loading level: " << level_name << std::endl;
    json j;
    std::string level_loc = "assets/levels/" + level_name;
    std::ifstream i(level_loc);
    i >> j;

    bool moving_camera = j["moving_camera"];
    std::vector<std::string> level = j["level"];


}

Player &World::get_player() {
    return player;
}
