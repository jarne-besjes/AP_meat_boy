//
// Created by jarne on 11/16/22.
//

#ifndef MEAT_BOY_VIEW_FACTORY_H
#define MEAT_BOY_VIEW_FACTORY_H
#include <memory>
#include "SFML/Graphics.hpp"
#include "Main_menu.h"

class Game;


class View_factory {

    Game &game;

    Main_menu menu;


public:
    explicit View_factory(Game &game);

    std::unique_ptr<sf::RenderWindow> draw_menu(std::unique_ptr<sf::RenderWindow> window);

    std::unique_ptr<sf::RenderWindow> draw_level(std::unique_ptr<sf::RenderWindow> window);

};


#endif //MEAT_BOY_VIEW_FACTORY_H
