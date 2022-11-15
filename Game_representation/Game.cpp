//
// Created by jarne on 11/13/22.
//

#include "Game.h"

// Also change this in Player.cpp (these classes should be in seperate libraries, so we cant include this file)
// TODO: maybe make a VALUES.cpp file that contains all the values
static int WINDOW_WIDTH = 800;
static int WINDOW_HEIGHT = 1000;

Game::Game() : menu(Main_menu(*this)) {

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
            if (show_menu) {
                window->clear();
                menu.draw();
                window = menu.display(std::move(window));
                menu.update();
            } else {
/*
                if (left || right || down || up)
                    world.get_player().key_pressed(left, right, down, up);
*/
                world.get_player().update(left, right, down, up);
            }
            window->display();
        }
}

void Game::display_level() {
        sf::Texture dirt_texture;
        sf::Texture meat_boy_texture;
        dirt_texture.loadFromFile("Game_representation/assets/textures/tex_dirt.jpg");
        meat_boy_texture.loadFromFile("Game_representation/assets/textures/meatboy.png");

        sf::Sprite dirt_sprite(dirt_texture);
        sf::Sprite meat_boy_sprite(meat_boy_texture);
        dirt_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
        Position player_position = world.get_player().get_position();
        meat_boy_sprite.setPosition(player_position.x, player_position.y);

        window->draw(meat_boy_sprite);
}

Game::~Game() {
}

void Game::close_window() {
    window->close();
}

void Game::play_button_pressed() {
    show_menu = false;
    current_level = "level1";
    world.load_level("level1.json");
}

void Game::update() {
    display_level();
}

void Game::add_game_to_player_observer() {
    world.get_player().register_observer(shared_from_this());
}
