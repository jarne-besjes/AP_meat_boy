//
// Created by jarne on 11/13/22.
//

#include "Game.h"
#include <filesystem>
#include <iostream>
#include <chrono>
#include <thread>
#include "../Values.cpp"
#include <fstream>

// Also change this in Player.cpp (these classes should be in seperate libraries, so we cant include this file)
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

    std::cout << &state_manager << std::endl;

    while (window->isOpen()) {
        Game_state game_state = state_manager.get_state();

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
        } else if (game_state == Game_state::GAME) {
            world.get_player().update(left, right, down, up, world.get_entities());
            window = view.draw_entities(std::move(window), world.get_entities());
            if (moving_camera) {
                if (world.get_player().get_position().y < camera.get_y()) {
                    camera.move_up(std::abs(world.get_player().get_position().y - camera.get_y()));
                } else if (world.get_player().get_position().y > camera.get_y() + WINDOW_HEIGHT/2) {
                    // TODO: die
                    state_manager.set_state(Game_state::MENU);
                }
            }

            if (world.get_player().collides_with_finish()) {
                // TODO
                std::cout << "You won!" << std::endl;
                state_manager.set_state(Game_state::FINISHED);
            }
        } else if (game_state == Game_state::LEVEL_CHOICE) {
            std::string level;
            std::string path = "assets/levels";
            std::vector<std::string> levels;
            for (const auto &entry : std::filesystem::directory_iterator(path)) {
                if (entry.path().extension() == ".json") {
                    levels.push_back(entry.path().string());
                }
            }
            window = view.draw_level_choice(std::move(window), levels, level);
            if (!level.empty()) {
                std::cout << level << std::endl;
                int level_size = world.load_level(level, moving_camera);
                camera.set_level_size(level_size);
                state_manager.set_state(Game_state::GAME);
            }
        } else if (game_state == Game_state::FINISHED) {
            bool enter_has_been_pressed = false;
            window = view.draw_finished(std::move(window), enter_has_been_pressed);
            if (enter_has_been_pressed) {
                state_manager.set_state(Game_state::MENU);
            }
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
    state_manager.set_state(Game_state::LEVEL_CHOICE);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
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

Camera &Game::get_camera() {
    return camera;
}

