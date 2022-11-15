//
// Created by jarne on 11/13/22.
//

#ifndef PLOTTER_GAME_H
#define PLOTTER_GAME_H
#include "SFML/Graphics.hpp"
#include "Main_menu.h"
#include <memory>
#include "../Game_logic/World.h"
#include "../Game_logic/Player.h"


class Game : public IObserver, public std::enable_shared_from_this<Game> {

    World world;

    bool show_menu = true;

    sf::Font main_font;

    //sf::RenderWindow *window;

    std::unique_ptr<sf::RenderWindow> window;

    std::string current_level;

    Main_menu menu;
public:

    void add_game_to_player_observer();

    void update() override;

    Game();

    void close_window();

    void display_level();

    void display_menu();

    void loop();

    void play_button_pressed();

    ~Game();
};


#endif //PLOTTER_GAME_H
