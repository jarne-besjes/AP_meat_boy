//
// Created by jarne on 11/13/22.
//

#ifndef MEAT_BOY_PLAYER_H
#define MEAT_BOY_PLAYER_H

enum class Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

struct Position {
    double x;
    double y;
};

class Player {
    double position_x, position_y;
    double velocity_x, velocity_y;

public:
    void key_pressed(Direction direction);

    void update();

    Position get_position();

};


#endif //MEAT_BOY_PLAYER_H
