//
// Created by jarne on 11/13/22.
//

#ifndef MEAT_BOY_MAIN_MENU_H
#define MEAT_BOY_MAIN_MENU_H
#include "SFML/Graphics.hpp"
#include <memory>

class Game;

class Main_menu {
    Game &game;

    sf::Font main_font;

    sf::Text game_title;
    sf::Text play_button;
    sf::Text quit_button;

    bool play_button_selected = true;
    bool quit_button_selected = false;
    bool play_button_pressed = false;
    bool quit_button_pressed = false;

public:
    explicit Main_menu(Game &game);

    void update();

    void draw();

    std::unique_ptr<sf::RenderWindow> display(std::unique_ptr<sf::RenderWindow> window);

};


#endif //MEAT_BOY_MAIN_MENU_H
