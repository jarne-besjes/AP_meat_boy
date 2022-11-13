//
// Created by jarne on 11/13/22.
//

#include "Game.h"

static int WINDOW_WIDTH = 800;
static int WINDOW_HEIGHT = 600;

Game::Game() : menu(Main_menu(*this)) {

    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Meat boy!");

    main_font.loadFromFile("Game_representation/assets/Debrosee.ttf");
}

void Game::loop() {
    bool left, right, down, up = false;
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
                world.get_player().key_pressed(left, right, down, up);
                world.get_player().update();
                display_level();
            }
            window->display();
        }
}

void Game::display_level() {
        sf::Texture dirt_texture;
        dirt_texture.loadFromFile("Game_representation/assets/textures/tex_dirt.jpg");

        sf::Sprite dirt_sprite(dirt_texture);
        dirt_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
        Position player_position = world.get_player().get_position();
        dirt_sprite.setPosition(player_position.x, player_position.y);

        std::cout << "Player position: " << player_position.x << ", " << player_position.y << std::endl;

        window->draw(dirt_sprite);

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
