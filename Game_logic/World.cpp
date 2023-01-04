//
// Created by jarne on 11/13/22.
//

#include "World.h"
#include "../include/json.hpp"
#include <fstream>
#include "Blocks/Entity.h"
#include "Blocks/Entity_factory.h"

using json = nlohmann::json;

namespace Game_logic {

/**
 * @brief Create a entity object
 *
 * @param factory : the factory to create the object with
 * @param x : x coordinate of the entity
 * @param y : y coordinate of the entity
 * @param width : width of the entity
 * @param height : height of the entity
 *
 * @return std::shared_ptr<Entity> : the created entity
 */
    std::shared_ptr<Entity>
    create_entity(std::shared_ptr<Entity_factory> &factory, int x, int y, int width, int height) {
        return factory->create_entity(x, y, width, height);
    }

/**
 * @brief Load the level from a json file
 *
 * @param level_name : the path of the level to load
 * @param moving_camera : true if the camera has to move up when the player moves up
 *
 * @return int : level_size
 */
    int World::load_level(const std::string &level_name, bool &moving_camera) {

        int nr_of_teleporters = 0;

        entities.clear();
        player.reset();
        // factories
        std::shared_ptr<Entity_factory> dirt_factory = std::make_shared<Dirt_factory>();
        std::shared_ptr<Entity_factory> grass_factory = std::make_shared<Grass_factory>();
        std::shared_ptr<Entity_factory> finish_factory = std::make_shared<Finish_factory>();
        std::shared_ptr<Entity_factory> saw_factory = std::make_shared<Saw_factory>();
        std::shared_ptr<Entity_factory> teleporter_factory = std::make_shared<Teleporter_factory>();

        json j;
        const std::string &level_loc = level_name;
        std::ifstream i(level_loc);
        i >> j;
        i.close();

        moving_camera = j["moving_camera"];
        std::vector<std::string> level = j["level"];

        bool finish_set = false;
        bool player_set = false;
        for (int y = 0; y < level.size(); y++) {
            for (int x = 0; x < level[y].size(); x++) {
                if (level[y][x] == 'g') {
                    entities.push_back(create_entity(grass_factory, x * 50, y * 50, 50, 50));
                } else if (level[y][x] == 'd') {
                    entities.push_back(create_entity(dirt_factory, x * 50, y * 50, 50, 50));
                } else if (level[y][x] == 'p') {
                    player.set_position(x * 50, y * 50);
                    player_set = true;
                } else if (level[y][x] == 'f') {
                    entities.push_back(create_entity(finish_factory, x * 50, y * 50, 50, 50));
                    finish_set = true;
                } else if (level[y][x] == 's') {
                    entities.push_back(create_entity(saw_factory, x * 50, y * 50, 50, 50));
                } else if (level[y][x] == 't') {
                    if (++nr_of_teleporters > 2) {
                        throw std::runtime_error("Too many teleporters in level");
                    }
                    entities.push_back(create_entity(teleporter_factory, x * 50, y * 50, 50, 50));
                }
            }
        }
        if (!finish_set || !player_set) {
            throw std::runtime_error("Finish or player not set");
        }

        return level.size();
    }

/**
 * @brief returns a reference to the player object
 *
 * @return Player& : the player object
 */
    Player &World::get_player() {
        return player;
    }

/**
 * @brief returns a reference to a vector of all entities in the world
 *
 * @return std::vector<std::shared_ptr<Entity>>& : the vector of entities
 */
    std::vector<std::shared_ptr<Entity>> &World::get_entities() {
        return entities;
    }

/**
 * @brief Construct a new World:: World object
 *
 */
    World::World() : finish(0, 0, 50, 50) {

    }

}
