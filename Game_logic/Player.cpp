//
// Created by jarne on 11/13/22.
//

#include "Player.h"
#include <math.h>
#include <iostream>

static double PLAYER_MAX_SPEED = 5.0;
static double PLAYER_ACCELERATION = 0.5;


void Player::update() {

}

void Player::key_pressed(Direction direction) {

}

Position Player::get_position() {
    return Position{position_x, position_y};
}
