//
// Created by jarne on 11/13/22.
//

#ifndef MEAT_BOY_WORLD_H
#define MEAT_BOY_WORLD_H
#include <iostream>
#include "Player.h"

class Entity;

class World {

    Player player;

    std::vector<std::shared_ptr<Entity>> entities;

public:
    void load_level(const std::string& level_name);
    Player &get_player();

    std::vector<std::shared_ptr<Entity>> &get_entities();
};


#endif //MEAT_BOY_WORLD_H
