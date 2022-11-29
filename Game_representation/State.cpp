//
// Created by jarne on 11/19/22.
//

#include "State.h"

Game_state State_manager::get_state() const {
    return current_state;
}

void State_manager::set_state(Game_state state) {
    current_state = state;
}

State_manager::State_manager() {
    current_state = Game_state::MENU;
}
