//
// Created by jarne on 12/1/22.
//

#ifndef MEAT_BOY_FINISHED_MENU_H
#define MEAT_BOY_FINISHED_MENU_H

#include <SFML/Graphics.hpp>
#include "After_game_menu.h"
#include <memory>

namespace Game_representation {

    class Finished_menu : public After_game_menu {
    public:
        Finished_menu() = default;

        std::unique_ptr<sf::RenderWindow> draw(std::unique_ptr<sf::RenderWindow> window) override;

        bool update() override; // if bool == true, the enter key has been pressed, so we need to go to the main menu
    };
}

#endif //MEAT_BOY_FINISHED_MENU_H
