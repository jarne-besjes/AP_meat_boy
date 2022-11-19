//
// Created by jarne on 11/13/22.
//

#include "Game.h"

// Also change this in Player.cpp (these classes should be in seperate libraries, so we cant include this file)
// TODO: maybe make a VALUES.cpp file that contains all the values
static int WINDOW_WIDTH = 600;
static int WINDOW_HEIGHT = 600;
static int FRAME_TIME = 16;

Game::Game() : view(*this){

    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Meat boy!");

    main_font.loadFromFile("Game_representation/assets/Debrosee.ttf");

}

void Game::loop() {
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right)
                    right = true;
                if (event.key.code == sf::Keyboard::Left)
                    left = true;
                if (event.key.code == sf::Keyboard::Up)
                    up = true;
                if (event.key.code == sf::Keyboard::Down)
                    down = true;
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Right)
                    right = false;
                if (event.key.code == sf::Keyboard::Left)
                    left = false;
                if (event.key.code == sf::Keyboard::Up)
                    up = false;
                if (event.key.code == sf::Keyboard::Down)
                    down = false;
            }
        }

        window->clear();
        if (game_state == Game_state::MENU) {
            bool close_window = false;
            window = view.draw_menu(std::move(window), close_window);
            if (close_window) {
                window->close();
            }
        } else {
            world.get_player().update(left, right, down, up, world.get_entities());
            window = view.draw_entities(std::move(window), world.get_entities());
        }
        window->display();
    }
}

void Game::display_level() {
    window = view.draw_level(std::move(window));
}

Game::~Game() {
}

void Game::play_button_pressed() {
    game_state = Game_state::GAME;
    current_level = "level1";
    world.load_level("level1.json");
}

void Game::update() {
    display_level();
}

void Game::add_game_to_player_observer() {
    world.get_player().register_observer(shared_from_this());
}

World &Game::get_world() {
    return world;
}

