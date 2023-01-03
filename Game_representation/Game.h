//
// Created by jarne on 11/13/22.
//

#ifndef PLOTTER_GAME_H
#define PLOTTER_GAME_H

#include "SFML/Graphics.hpp"
#include "View.h"
#include <memory>
#include "../Game_logic/World.h"
#include "../Game_logic/Player.h"
#include "../Stopwatch.h"
#include "State.h"
#include "../Camera.h"

namespace Game_representation {

    class Game : public IObserver, public std::enable_shared_from_this<Game> {

        //   Stopwatch &stopwatch = Stopwatch::getInstance();

        Camera camera;

        View view;

        State_manager state_manager;

        Game_logic::World world;
        sf::Font main_font;

        std::unique_ptr<sf::RenderWindow> window;

        std::string current_level;

        bool moving_camera;

    public:

        void add_game_to_player_observer();

        void update() override;

        Game();

        void display_level();

        Game_logic::World &get_world();

        void loop();

        void play_button_pressed();

        Camera &get_camera();

        ~Game();
    };

}


#endif //PLOTTER_GAME_H
