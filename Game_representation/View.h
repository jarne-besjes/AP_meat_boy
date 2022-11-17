//
// Created by jarne on 11/16/22.
//

#ifndef MEAT_BOY_VIEW_H
#define MEAT_BOY_VIEW_H
#include <memory>
#include "SFML/Graphics.hpp"
#include "Main_menu.h"

class Game;


class View {

    Game &game;

    Main_menu menu;


public:
    explicit View(Game &game);

    std::unique_ptr<sf::RenderWindow> draw_menu(std::unique_ptr<sf::RenderWindow> window, bool &has_to_close);

    std::unique_ptr<sf::RenderWindow> draw_level(std::unique_ptr<sf::RenderWindow> window);

};


#endif //MEAT_BOY_VIEW_H
