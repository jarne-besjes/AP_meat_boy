//
// Created by jarne on 12/1/22.
//

#ifndef MEAT_BOY_FINISHED_MENU_H
#define MEAT_BOY_FINISHED_MENU_H

#include <SFML/Graphics.hpp>
#include <memory>

class Finished_menu {
    sf::Font main_font;

    //sf::View view;

public:
    Finished_menu();

    std::unique_ptr<sf::RenderWindow> draw(std::unique_ptr<sf::RenderWindow> window);

    bool update(); // if bool == true, the enter key has been pressed, so we need to go to the main menu
};


#endif //MEAT_BOY_FINISHED_MENU_H
