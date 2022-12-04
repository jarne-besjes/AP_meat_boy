//
// Created by jarne on 11/19/22.
//

#include "State.h"

/**
 * @brief Get the current state of the game
 * 
 * @return Game_state : current state of the game
 */
Game_state State_manager::get_state() const {
    return current_state;
}

/**
 * @brief Set the current state of the game
 * 
 * @param state : state to set the game to
 */
void State_manager::set_state(Game_state state) {
    current_state = state;
}

/**
 * @brief Construct a new State_manager::State_manager object
 * 
 */
State_manager::State_manager() {
    current_state = Game_state::MENU;
}
