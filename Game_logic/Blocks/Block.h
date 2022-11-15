//
// Created by jarne on 11/14/22.
//

#ifndef MEAT_BOY_BLOCK_H
#define MEAT_BOY_BLOCK_H


enum class Block_type {
    DIRT,
    GRASS,
    END
};

class Block {
    double x;
    double y;
    bool damages;
    Block_type type;

    Block(double x, double y, Block_type type);
};


#endif //MEAT_BOY_BLOCK_H
