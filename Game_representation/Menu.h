//
// Created by jarne on 1/5/23.
//

#ifndef MEAT_BOY_MENU_H
#define MEAT_BOY_MENU_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace Game_representation {
    class Menu {
    protected:
        sf::Font font;

    public:
        Menu();

        virtual std::unique_ptr<sf::RenderWindow> draw(std::unique_ptr<sf::RenderWindow> window) = 0;

        virtual bool update() = 0;

        virtual ~Menu() = default;
    };

}

#endif //MEAT_BOY_MENU_H
