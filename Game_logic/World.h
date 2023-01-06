//
// Created by jarne on 11/13/22.
//

#ifndef MEAT_BOY_WORLD_H
#define MEAT_BOY_WORLD_H

#include <iostream>
#include "Player.h"
#include "../Camera.h"
#include "Blocks/Finish.h"

namespace Game_logic {
    class Entity;

    class World {

        Player player;

        Finish finish;

        std::vector<std::shared_ptr<Entity>> entities;

        bool automatic_camera =false;

    public:
        World();

        int load_level(const std::string &level_name,
                       bool &moving_camera); // returns the level y size for the initialization of the camera
        Player &get_player();

        std::vector<std::shared_ptr<Entity>> &get_entities();
    };

}


#endif //MEAT_BOY_WORLD_H
