//
// Created by jarne on 11/16/22.
//

#include "View.h"
#include "Game.h"
#include "../Game_logic/Blocks/Entity.h"
#include "../Values.cpp"


std::unique_ptr<sf::RenderWindow> View::draw_menu(std::unique_ptr<sf::RenderWindow> window, bool &has_to_close) {
    menu.draw();
    window = menu.display(std::move(window));
    has_to_close = menu.update();

    return window;
}

View::View(Game &game): game(game), menu(game) {
    view = sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
    main_font.loadFromFile("Game_representation/assets/Freshman-POdx.ttf");
}

std::unique_ptr<sf::RenderWindow> View::draw_level(std::unique_ptr<sf::RenderWindow> window) {
    window->setView(view);

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

std::unique_ptr<sf::RenderWindow>
View::draw_entities(std::unique_ptr<sf::RenderWindow> window, std::vector<std::shared_ptr<Entity>> &entities) {
    sf::Texture dirt_texture;
    sf::Texture grass_texture;
    sf::Texture finish_texture;
    // TODO: try catch
    dirt_texture.loadFromFile("Game_representation/assets/textures/tex_dirt.jpg");
    grass_texture.loadFromFile("Game_representation/assets/textures/tex_grass.jpg");
    finish_texture.loadFromFile("Game_representation/assets/textures/finish.png");

    sf::Sprite dirt_sprite(dirt_texture);
    sf::Sprite grass_sprite(grass_texture);
    sf::Sprite finish_sprite(finish_texture);
    dirt_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    grass_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    finish_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));


    for (auto &entity : entities) {
        int pos_x = entity->get_x();
        int pos_y = entity->get_y();
        if (entity->get_type() == Block_type::DIRT) {
            dirt_sprite.setPosition(pos_x, pos_y);
            window->draw(dirt_sprite);
        } else if (entity->get_type() == Block_type::GRASS) {
            grass_sprite.setPosition(pos_x, pos_y);
            window->draw(grass_sprite);
        } else if (entity->get_type() == Block_type::FINISH) {
            finish_sprite.setPosition(pos_x, pos_y);
            window->draw(finish_sprite);
        }
    }


    return window;
}

std::unique_ptr<sf::RenderWindow>
View::draw_level_choice(std::unique_ptr<sf::RenderWindow> window, const std::vector<std::string> &levels, std::string &level) {
    window = selection.draw(std::move(window), levels);
    window = selection.update(std::move(window), levels, level);

    return window;
}

std::unique_ptr<sf::RenderWindow> View::draw_finished(std::unique_ptr<sf::RenderWindow> window, bool &enter_has_been_pressed) {
    window = finished_menu.draw(std::move(window));
    enter_has_been_pressed = finished_menu.update();

    return window;
}


