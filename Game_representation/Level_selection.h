//
// Created by jarne on 11/29/22.
//

#ifndef MEAT_BOY_LEVEL_SELECTION_H
#define MEAT_BOY_LEVEL_SELECTION_H
#include <memory>
#include <SFML/Graphics.hpp>
#include <vector>


class Level_selection {

    sf::Font main_font;

    int selected_level = 0;

public:
    Level_selection();


    std::unique_ptr<sf::RenderWindow>
    draw(std::unique_ptr<sf::RenderWindow> window, const std::vector<std::string> &levels);

    std::unique_ptr<sf::RenderWindow> update(std::unique_ptr<sf::RenderWindow> window, const std::vector<std::string> &levels, std::string &level);
};


#endif //MEAT_BOY_LEVEL_SELECTION_H
