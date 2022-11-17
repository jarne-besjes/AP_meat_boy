//
// Created by jarne on 11/17/22.
//

#ifndef MEAT_BOY_ENTITY_FACTORY_H
#define MEAT_BOY_ENTITY_FACTORY_H
#include <memory>

class Entity;

class Entity_factory {
public:
    virtual std::unique_ptr<Entity> create_entity(int x, int y, int width, int height) = 0;

};

class Grass_factory : public Entity_factory {
public:
    std::unique_ptr<Entity> create_entity(int x, int y, int width, int height) override;
};

class Dirt_factory : public Entity_factory {
    std::unique_ptr<Entity> create_entity(int x, int y, int width, int height) override;
};


#endif //MEAT_BOY_ENTITY_FACTORY_H
