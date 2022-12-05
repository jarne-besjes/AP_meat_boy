//
// Created by jarne on 11/19/22.
//

#ifndef MEAT_BOY_HITBOX_H
#define MEAT_BOY_HITBOX_H

class Hitbox {
public:
    Hitbox(double x, double y, double w, double h);


    double x;
    double y;
    double w;
    double h;

    double top_side;
    double bottom_side;
    double left_side;
    double right_side;

    bool collides(const Hitbox &other) const;

    double get_top() const;
    double get_bottom() const;
    double get_left() const;
    double get_right() const;

    // functions to check collisions: check if THIS OBJECT COLLIDES with the ... side of the other object
    bool collides_left_side(const Hitbox &other) const;
    bool collides_right_side(const Hitbox &other) const;
    bool collides_top_side(const Hitbox &other) const;
    bool collides_bottom_side(const Hitbox &other) const;

};


#endif //MEAT_BOY_HITBOX_H
