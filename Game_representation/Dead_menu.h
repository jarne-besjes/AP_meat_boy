//
// Created by jarne on 1/5/23.
//

#ifndef MEAT_BOY_DEAD_MENU_H
#define MEAT_BOY_DEAD_MENU_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Menu.h"

namespace Game_representation {
    class Dead_menu : public Menu {
    public:

        std::unique_ptr<sf::RenderWindow> draw(std::unique_ptr<sf::RenderWindow> window) override;

        bool update() override;

    };
}


#endif //MEAT_BOY_DEAD_MENU_H
