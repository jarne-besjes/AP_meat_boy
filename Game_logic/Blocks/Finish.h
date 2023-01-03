//
// Created by jarne on 11/30/22.
//

#ifndef MEAT_BOY_FINISH_H
#define MEAT_BOY_FINISH_H
#include "Entity.h"

namespace Game_logic {

    class Finish : public Entity{
    public:

        Finish(int x, int y, int width, int height);
        ~Finish() override = default;

        Block_type get_type() const override;

        Game_logic::Hitbox get_hitbox() const override;
    };
}


#endif //MEAT_BOY_FINISH_H
