//
// Created by jarne on 11/16/22.
//

#ifndef MEAT_BOY_VIEW_H
#define MEAT_BOY_VIEW_H
#include <memory>
#include "SFML/Graphics.hpp"
#include "Main_menu.h"
#include "Level_selection.h"
#include "Finished_menu.h"

class Game;

class Entity;

class View {

    Game &game;

    Main_menu menu;

    Level_selection selection;

    Finished_menu finished_menu;

    //sf::View view;

    sf::Font main_font;

public:
    explicit View(Game &game);

    std::unique_ptr<sf::RenderWindow> draw_menu(std::unique_ptr<sf::RenderWindow> window, bool &has_to_close);

    std::unique_ptr<sf::RenderWindow> draw_level(std::unique_ptr<sf::RenderWindow> window);

    static std::unique_ptr<sf::RenderWindow> draw_entities(std::unique_ptr<sf::RenderWindow> window, std::vector<std::shared_ptr<Entity>> &entities);

    std::unique_ptr<sf::RenderWindow>
    draw_level_choice(std::unique_ptr<sf::RenderWindow> window, const std::vector<std::string> &levels, std::string &level);

    std::unique_ptr<sf::RenderWindow> draw_finished(std::unique_ptr<sf::RenderWindow> window, bool &enter_has_been_pressed);
};


#endif //MEAT_BOY_VIEW_H
