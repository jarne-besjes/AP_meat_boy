//
// Created by jarne on 11/13/22.
//

#include "World.h"
#include "../include/json.hpp"
#include <fstream>
#include "Blocks/Entity.h"
#include "Blocks/Entity_factory.h"

using json = nlohmann::json;

std::shared_ptr<Entity> create_entity(std::shared_ptr<Entity_factory> &factory, int x, int y, int width, int height) {
    return factory->create_entity(x, y, width, height);
}

void World::load_level(const std::string& level_name) {
    // factories
    std::shared_ptr<Entity_factory> dirt_factory = std::make_shared<Dirt_factory>();
    std::shared_ptr<Entity_factory> grass_factory = std::make_shared<Grass_factory>();
    std::shared_ptr<Entity_factory> finish_factory = std::make_shared<Finish_factory>();

    json j;
    const std::string &level_loc = level_name;
    std::ifstream i(level_loc);
    i >> j;

    bool moving_camera = j["moving_camera"];
    std::vector<std::string> level = j["level"];

    bool finish_set = false;
    bool player_set = false;
    for (int y = 0; y < level.size(); y++) {
        for (int x = 0; x < level[y].size(); x++) {
            if (level[y][x] == 'g') {
                entities.push_back(create_entity(grass_factory, x * 50, y * 50, 50, 50));
            } else if (level[y][x] == 'd') {
                entities.push_back(create_entity(dirt_factory, x * 50, y * 50, 50, 50));
            } else if(level[y][x] == 'p') {
                player.set_position(x * 50, y * 50);
                player_set = true;
            } else if (level[y][x] == 'f') {
                entities.push_back(create_entity(finish_factory, x * 50, y * 50, 50, 50));
                finish_set = true;
            }
        }
    }
    if (!finish_set || !player_set) {
        throw std::runtime_error("Finish or player not set");
    }
}

Player &World::get_player() {
    return player;
}

std::vector<std::shared_ptr<Entity>> &World::get_entities() {
    return entities;
}

World::World(): finish(0,0,50, 50) {

}
