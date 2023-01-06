//
// Created by jarne on 11/13/22.
//

#ifndef MEAT_BOY_MAIN_MENU_H
#define MEAT_BOY_MAIN_MENU_H

#include "SFML/Graphics.hpp"
#include "Menu.h"
#include <memory>

namespace Game_representation {

    class Game;

    class Main_menu : Menu {
        Game &game;

        sf::Text game_title;
        sf::Text play_button;
        sf::Text quit_button;

        bool play_button_selected = true;
        bool quit_button_selected = false;
        bool play_button_pressed = false;
        bool quit_button_pressed = false;

    public:
        explicit Main_menu(Game &game);

        bool update() override; // if bool == true, the game has to close

        std::unique_ptr<sf::RenderWindow> draw(std::unique_ptr<sf::RenderWindow> window) override;

        ~Main_menu() override = default;
    };

}

#endif //MEAT_BOY_MAIN_MENU_H
