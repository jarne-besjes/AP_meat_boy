//
// Created by jarne on 11/14/22.
//

#include "Block.h"

Block::Block(double x, double y, Block_type type): x(x), y(y), type(type) {

    // TODO: When more blocks are added create this if statement
    if (false) {
        damages = true;
    } else {
        damages = false;
    }
}
