//
// Created by jarne on 11/13/22.
//

#ifndef MEAT_BOY_WORLD_H
#define MEAT_BOY_WORLD_H
#include <iostream>
#include "Player.h"

class World {

    Player player;

public:
    void load_level(std::string level_name);
    Player &get_player();
};


#endif //MEAT_BOY_WORLD_H
