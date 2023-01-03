//
// Created by jarne on 11/17/22.
//

#ifndef MEAT_BOY_ENTITY_FACTORY_H
#define MEAT_BOY_ENTITY_FACTORY_H

#include <memory>

namespace Game_logic {

    class Entity;

    class Entity_factory {
    public:
        virtual std::unique_ptr<Entity> create_entity(int x, int y, int width, int height) = 0;

        virtual ~Entity_factory();
    };

    class Grass_factory : public Entity_factory {
    public:
        std::unique_ptr<Entity> create_entity(int x, int y, int width, int height) override;

        ~Grass_factory() override = default;
    };

    class Dirt_factory : public Entity_factory {
    public:
        std::unique_ptr<Entity> create_entity(int x, int y, int width, int height) override;

        ~Dirt_factory() override = default;
    };

    class Finish_factory : public Entity_factory {
    public:
        std::unique_ptr<Entity> create_entity(int x, int y, int width, int height) override;

        ~Finish_factory() override = default;
    };

    class Saw_factory : public Entity_factory {
    public:
        std::unique_ptr<Entity> create_entity(int x, int y, int width, int height) override;

        ~Saw_factory() override = default;
    };

}

#endif //MEAT_BOY_ENTITY_FACTORY_H
