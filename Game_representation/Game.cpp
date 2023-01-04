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

static double FRAME_TIME = 0.016;

namespace Game_representation {

/**
 * @brief Construct a new Game:: Game object
 *
 */
    Game::Game() : view(*this) {

        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Meat boy!");

        main_font.loadFromFile("Game_representation/assets/Debrosee.ttf");

    }

/**
 * @brief Main game loop
 *
 */
    void Game::loop() {
        bool left = false;
        bool right = false;
        bool up = false;
        bool down = false;

        Stopwatch *stopwatch = Stopwatch::getInstance();

        while (window->isOpen()) {
            if (stopwatch->elapsed() <= FRAME_TIME) continue; // we are allow to use busy waiting to cap the framerate

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
                camera.clear_visible_entities(world.get_entities());
                camera.get_visible_entities(world.get_entities());
                camera.project_entities(world.get_entities());
                camera.project_player(world.get_player());
                window = view.draw_entities(std::move(window), world.get_entities());
                if (moving_camera) {
                    if (world.get_player().get_position().y < camera.get_y()) {
                        camera.move_up(std::abs(world.get_player().get_position().y - camera.get_y()));
                    } else if (world.get_player().get_position().y > camera.get_y() + WINDOW_HEIGHT / 2) {
                        // TODO: die
                        state_manager.set_state(Game_state::MENU);
                    }
                }
                Game_logic::Entity *teleporter = world.get_player().collides_with_teleporter();

                if (world.get_player().collides_with_finish()) {
                    // TODO
                    std::cout << "You won!" << std::endl;
                    state_manager.set_state(Game_state::FINISHED);
                } else if (world.get_player().collides_with_deadly_object()) {
                    // TODO: die
                    state_manager.set_state(Game_state::MENU);
                } else if (teleporter) {
                    world.get_player().set_position(teleporter->get_x(), teleporter->get_y() - 50);
                }
            } else if (game_state == Game_state::LEVEL_CHOICE) {
                std::string level;
                std::string path = "assets/levels";
                std::vector<std::string> levels;
                for (const auto &entry: std::filesystem::directory_iterator(path)) {
                    if (entry.path().extension() == ".json") {
                        levels.push_back(entry.path().string());
                    }
                }
                window = view.draw_level_choice(std::move(window), levels, level);
                if (!level.empty()) {
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
            Stopwatch::getInstance()->next_frame();
        }
    }

/**
 * @brief display the level on the screen
 *
 */
    void Game::display_level() {
        window = view.draw_level(std::move(window));
    }

/**
 * @brief Destroy the Game:: Game object
 *
 */
    Game::~Game() {
    }

/**
 * @brief Change the game state to level choice
 *
 */
    void Game::play_button_pressed() {
        state_manager.set_state(Game_state::LEVEL_CHOICE);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

/**
 * @brief update the game
 *
 */
    void Game::update() {
        display_level();
    }

/**
 * @brief add this game object to the player observer
 *
 */
    void Game::add_game_to_player_observer() {
        world.get_player().register_observer(shared_from_this());
    }

/**
 * @brief Get the world object
 *
 * @return World& : the world
 */
    Game_logic::World &Game::get_world() {
        return world;
    }

/**
 * @brief Get the camera object
 *
 * @return Camera& : the camera
 */
    Camera &Game::get_camera() {
        return camera;
    }


}
