//
// Created by jarne on 1/5/23.
//

#ifndef MEAT_BOY_AFTER_GAME_MENU_H
#define MEAT_BOY_AFTER_GAME_MENU_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace Game_representation {
    class After_game_menu {
    protected:
        sf::Font font;

    public:
        After_game_menu();

        virtual std::unique_ptr<sf::RenderWindow> draw(std::unique_ptr<sf::RenderWindow> window) = 0;

        virtual bool update() = 0;

        virtual ~After_game_menu() = default;
    };

}

#endif //MEAT_BOY_AFTER_GAME_MENU_H
