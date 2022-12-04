//
// Created by jarne on 11/30/22.
//

#ifndef MEAT_BOY_FINISH_H
#define MEAT_BOY_FINISH_H
#include "Entity.h"

class Finish : public Entity{
public:

    Finish(int x, int y, int width, int height);

    Block_type get_type() const override;

    Hitbox get_hitbox() const override;

};


#endif //MEAT_BOY_FINISH_H