//
// Created by jarne on 11/13/22.
//

#ifndef MEAT_BOY_PLAYER_H
#define MEAT_BOY_PLAYER_H

#include "Hitbox.h"

#include "../Observer.h"
#include "Blocks/Entity.h"

namespace Game_logic {

// Use this to easily pass position to the representation library
    struct Position {
        double x;
        double y;
    };

    class Player : public IObservable{
        double position_x, position_y;
        double velocity_x, velocity_y;

        bool on_ground = false;

        bool against_wall = false;
        bool against_wall_left = false;

        bool collided_with_finish = false;

    public:
        Player();

        void reset();

        void set_position(double x, double y);

        void update(bool left, bool right, bool down, bool up, std::vector<std::shared_ptr<Entity>> &entities);

        Position get_position();

        Position get_projected_position();

        bool collides_with_finish() const {
            return collided_with_finish;
        }

        Hitbox get_hitbox();

        ~Player() override = default;

        double projected_x = 0;
        double projected_y = 0;
    };
}

#endif //MEAT_BOY_PLAYER_H
