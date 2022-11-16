//
// Created by jarne on 11/16/22.
//

#include "View_factory.h"
#include "Game.h"

// Also change this in Player.cpp (these classes should be in seperate libraries, so we cant include this file)
// TODO: maybe make a VALUES.cpp file that contains all the values
static int WINDOW_WIDTH = 800;
static int WINDOW_HEIGHT = 1000;

std::unique_ptr<sf::RenderWindow> View_factory::draw_menu(std::unique_ptr<sf::RenderWindow> window) {
    menu.draw();
    window = menu.display(std::move(window));
    menu.update();

    return window;
}

View_factory::View_factory(Game &game): game(game), menu(game) {
}

std::unique_ptr<sf::RenderWindow> View_factory::draw_level(std::unique_ptr<sf::RenderWindow> window) {

    sf::Texture dirt_texture;
    sf::Texture meat_boy_texture;
    dirt_texture.loadFromFile("Game_representation/assets/textures/tex_dirt.jpg");
    meat_boy_texture.loadFromFile("Game_representation/assets/textures/meatboy.png");

    sf::Sprite dirt_sprite(dirt_texture);
    sf::Sprite meat_boy_sprite(meat_boy_texture);
    dirt_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    Position player_position = game.get_world().get_player().get_position();
    meat_boy_sprite.setPosition(player_position.x, player_position.y);

    window->draw(meat_boy_sprite);


    return window;
}
