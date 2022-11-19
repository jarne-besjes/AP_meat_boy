//
// Created by jarne on 11/15/22.
//

#ifndef MEAT_BOY_ENTITY_H
#define MEAT_BOY_ENTITY_H

#include <SFML/Graphics.hpp>
#include "../Hitbox.h"
// we use this enum to determine what type of block we are dealing with
// we use inheritance to be able to expand later

enum class Block_type {
    GRASS,
    DIRT,
};

class Entity {
protected:
    int x;
    int y;
    int width;
    int height;

    Block_type block_type;
public:
    Entity(int x, int y, int width, int height);

    virtual Block_type get_type() const = 0;

    virtual Hitbox get_hitbox() const = 0;


    int get_x() const;
    int get_y() const;
    int get_width() const;
    int get_height() const;

};

class GrassBlock : public Entity {
public:
    GrassBlock(int x, int y, int width, int height);

    Block_type get_type() const override;

    Hitbox get_hitbox() const override;

};

class DirtBlock : public Entity {
public:
    DirtBlock(int x, int y, int width, int height);

    Block_type get_type() const override;

    Hitbox get_hitbox() const override;
};

#endif //MEAT_BOY_ENTITY_H
