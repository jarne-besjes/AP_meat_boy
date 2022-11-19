//
// Created by jarne on 11/19/22.
//

#ifndef MEAT_BOY_HITBOX_H
#define MEAT_BOY_HITBOX_H

class Hitbox {
public:
    Hitbox(int x, int y, int w, int h);


    int x;
    int y;
    int w;
    int h;

    int top_side;
    int bottom_side;
    int left_side;
    int right_side;

    bool collides(const Hitbox &other) const;

    // functions to check collisions: check if THIS OBJECT COLLIDES with the ... side of the other object
    bool collides_left_side(const Hitbox &other) const;
    bool collides_right_side(const Hitbox &other) const;
    bool collides_top_side(const Hitbox &other) const;
    bool collides_bottom_side(const Hitbox &other) const;

};


#endif //MEAT_BOY_HITBOX_H
