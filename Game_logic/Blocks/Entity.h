//
// Created by jarne on 11/15/22.
//

#ifndef MEAT_BOY_ENTITY_H
#define MEAT_BOY_ENTITY_H

#include <SFML/Graphics.hpp>

// we use this enum to determine what type of block we are dealing with
// we use inheritance to be able to expand later

enum class Block_type {
    GRASS,
    DIRT,
};

class Entity {
    int x;
    int y;
    int width;
    int height;


protected:
    Block_type block_type;
public:
    Entity(int x, int y, int width, int height);

    virtual Block_type get_type() const = 0;

    virtual int get_x() const;
    virtual int get_y() const;
};

class GrassBlock : public Entity {
public:
    GrassBlock(int x, int y, int width, int height);

    Block_type get_type() const override;

};

class DirtBlock : public Entity {
public:
    DirtBlock(int x, int y, int width, int height);

    Block_type get_type() const override;
};

#endif //MEAT_BOY_ENTITY_H
