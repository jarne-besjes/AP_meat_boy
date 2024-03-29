//
// Created by jarne on 11/15/22.
//

#ifndef MEAT_BOY_ENTITY_H
#define MEAT_BOY_ENTITY_H

#include <SFML/Graphics.hpp>
#include "../Hitbox.h"
// we use this enum to determine what type of block we are dealing with
// we use inheritance to be able to expand later


namespace Game_logic {

    enum class Block_type {
        GRASS,
        DIRT,
        FINISH,
        SAW,
        TELEPORTER
    };

    class Entity {
    protected:
        double x;
        double y;
        double width;
        double height;

        Block_type block_type;
    public:

        bool visible = false;

        double projected_x = 0;
        double projected_y = 0;

        Entity(int x, int y, int width, int height);

        virtual ~Entity() = default;

        virtual Block_type get_type() const = 0;

        virtual Game_logic::Hitbox get_hitbox() const = 0;

        void set_position(int x, int y);

        int get_x() const;

        int get_y() const;

        int get_width() const;

        int get_height() const;

        double get_projected_x() const;

        double get_projected_y() const;
    };

    class GrassBlock : public Entity {
    public:
        GrassBlock(int x, int y, int width, int height);

        ~GrassBlock() override = default;

        Block_type get_type() const override;

        Game_logic::Hitbox get_hitbox() const override;
    };

    class DirtBlock : public Entity {
    public:
        DirtBlock(int x, int y, int width, int height);

        ~DirtBlock() override = default;

        Block_type get_type() const override;

        Game_logic::Hitbox get_hitbox() const override;

    };

    class SawBlade : public Entity {
    public:
        SawBlade(int x, int y, int width, int height);

        ~SawBlade() override = default;

        Block_type get_type() const override;

        Game_logic::Hitbox get_hitbox() const override;
    };

    class Teleporter : public Entity {
    public:
        Teleporter(int x, int y, int width, int height);

        ~Teleporter() override = default;

        Block_type get_type() const override;

        Game_logic::Hitbox get_hitbox() const override;
    };
}

#endif //MEAT_BOY_ENTITY_H
