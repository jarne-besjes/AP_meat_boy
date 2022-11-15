//
// Created by jarne on 11/13/22.
//

#ifndef MEAT_BOY_PLAYER_H
#define MEAT_BOY_PLAYER_H

#include "../Observer.h"

// Use this to easily pass position to the representation library
struct Position {
    double x;
    double y;
};

struct Hitbox {
    double x;
    double y;
    int w;
    int h;
};

class Player : public IObservable{
    double position_x, position_y;
    double velocity_x, velocity_y;

    bool jumping = false;

public:
    void key_pressed(bool left, bool right, bool down, bool up);

    void update(bool left, bool right, bool down, bool up);

    Position get_position();

    Hitbox get_hitbox();
};


#endif //MEAT_BOY_PLAYER_H
