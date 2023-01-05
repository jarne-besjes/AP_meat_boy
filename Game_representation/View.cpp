//
// Created by jarne on 11/16/22.
//

#include "View.h"
#include "Game.h"
#include "../Values.cpp"
#include "../Game_logic/Blocks/Entity.h"


namespace Game_representation {

/**
 * @brief draw the menu to the game
 *
 * @param window : window to draw the menu to
 * @param has_to_close : boolean to check if the game has to close
 * @return std::unique_ptr<sf::RenderWindow> : the window to draw the menu to
 */
    std::unique_ptr<sf::RenderWindow> View::draw_menu(std::unique_ptr<sf::RenderWindow> window, bool &has_to_close) {
        menu.draw();
        window = menu.display(std::move(window));
        has_to_close = menu.update();

        return window;
    }

/**
 * @brief Construct a new View:: View object
 *
 * @param game : the game object
 */
    View::View(Game &game) : game(game), menu(game) {
        main_font.loadFromFile("Game_representation/assets/Freshman-POdx.ttf");
    }

/**
 * @brief draw the level to the game
 *
 * @param window : window to draw the level to
 *
 * @return std::unique_ptr<sf::RenderWindow> : the window
 */
    std::unique_ptr<sf::RenderWindow> View::draw_level(std::unique_ptr<sf::RenderWindow> window) {

        sf::Texture dirt_texture;
        sf::Texture meat_boy_texture;
        dirt_texture.loadFromFile("Game_representation/assets/textures/tex_dirt.jpg");
        meat_boy_texture.loadFromFile("Game_representation/assets/textures/meatboy.png");

        sf::Sprite dirt_sprite(dirt_texture);
        sf::Sprite meat_boy_sprite(meat_boy_texture);
        dirt_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
        Game_logic::Position player_position = game.get_world().get_player().get_projected_position();
        meat_boy_sprite.setPosition(player_position.x, player_position.y);

        window->draw(meat_boy_sprite);

        return window;
    }

/**
 * @brief draw the entities to the game
 *
 * @param window : window to draw the entities to
 * @param entities : entities to draw
 *
 * @return std::unique_ptr<sf::RenderWindow> : the window
 */
    std::unique_ptr<sf::RenderWindow>
    View::draw_entities(std::unique_ptr<sf::RenderWindow> window,
                        std::vector<std::shared_ptr<Game_logic::Entity>> &entities) {
        sf::Texture dirt_texture;
        sf::Texture grass_texture;
        sf::Texture finish_texture;
        sf::Texture saw_texture_1;
        sf::Texture saw_texture_2;
        sf::Texture teleporter_texture1;
        sf::Texture teleporter_texture2;
        sf::Texture teleporter_texture3;

        // TODO: try catch and do this in constructor
        dirt_texture.loadFromFile("Game_representation/assets/textures/tex_dirt.jpg");
        grass_texture.loadFromFile("Game_representation/assets/textures/tex_grass.jpg");
        finish_texture.loadFromFile("Game_representation/assets/textures/finish.png");
        saw_texture_1.loadFromFile("Game_representation/assets/textures/sawBlade1.png");
        saw_texture_2.loadFromFile("Game_representation/assets/textures/sawBlade2.png");
        teleporter_texture1.loadFromFile("Game_representation/assets/textures/teleporter1.png");
        teleporter_texture2.loadFromFile("Game_representation/assets/textures/teleporter2.png");
        teleporter_texture3.loadFromFile("Game_representation/assets/textures/teleporter3.png");

        sf::Sprite dirt_sprite(dirt_texture);
        sf::Sprite grass_sprite(grass_texture);
        sf::Sprite finish_sprite(finish_texture);
        sf::Sprite saw_sprite_1(saw_texture_1);
        sf::Sprite saw_sprite_2(saw_texture_2);
        sf::Sprite teleporter_sprite1(teleporter_texture1);
        sf::Sprite teleporter_sprite2(teleporter_texture2);
        sf::Sprite teleporter_sprite3(teleporter_texture3);
        dirt_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
        grass_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
        finish_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
        saw_sprite_1.setTextureRect(sf::IntRect(0, 0, 50, 50));
        saw_sprite_2.setTextureRect(sf::IntRect(0, 0, 50, 50));
        teleporter_sprite1.setTextureRect(sf::IntRect(0, 0, 50, 50));
        teleporter_sprite2.setTextureRect(sf::IntRect(0, 0, 50, 50));
        teleporter_sprite3.setTextureRect(sf::IntRect(0, 0, 50, 50));



        for (auto &entity: entities) {

            if (!entity->visible) continue; // only draw the visible objects
            int pos_x = entity->get_projected_x();
            int pos_y = entity->get_projected_y();
            if (entity->get_type() == Game_logic::Block_type::DIRT) {
                dirt_sprite.setPosition(pos_x, pos_y);
                window->draw(dirt_sprite);
            } else if (entity->get_type() == Game_logic::Block_type::GRASS) {
                grass_sprite.setPosition(pos_x, pos_y);
                window->draw(grass_sprite);
            } else if (entity->get_type() == Game_logic::Block_type::FINISH) {
                finish_sprite.setPosition(pos_x, pos_y);
                window->draw(finish_sprite);
            } else if (entity->get_type() == Game_logic::Block_type::SAW) {
                static int saw_counter = 0;
                if ((++saw_counter) % 30 <= 15) {
                    if (saw_counter == 30) saw_counter = 0;
                    saw_sprite_1.setPosition(pos_x, pos_y);
                    window->draw(saw_sprite_1);
                } else {
                    saw_sprite_2.setPosition(pos_x, pos_y);
                    window->draw(saw_sprite_2);
                }
            } else if (entity->get_type() == Game_logic::Block_type::TELEPORTER) {
                static int teleporter_counter = 0;
                if ((++teleporter_counter) % 30 <= 10) {
                    if (teleporter_counter == 30) teleporter_counter = 0;
                    teleporter_sprite1.setPosition(pos_x, pos_y);
                    window->draw(teleporter_sprite1);
                } else if ((teleporter_counter) % 30 <= 20) {
                    teleporter_sprite2.setPosition(pos_x, pos_y);
                    window->draw(teleporter_sprite2);
                } else {
                    teleporter_sprite3.setPosition(pos_x, pos_y);
                    window->draw(teleporter_sprite3);
                }
            }
        }


        return window;
    }

/**
 * @brief Draw the level choice menu
 *
 * @param window : window to draw the menu to
 * @param levels : levels to draw
 * @param level : level that has been selected
 *
 * @return std::unique_ptr<sf::RenderWindow> : the window
 */
    std::unique_ptr<sf::RenderWindow>
    View::draw_level_choice(std::unique_ptr<sf::RenderWindow> window, const std::vector<std::string> &levels,
                            std::string &level) {
        window = selection.draw(std::move(window), levels);
        window = selection.update(std::move(window), levels, level);

        return window;
    }

/**
 * @brief draw the finished menu
 *
 * @param window : window to draw the menu to
 * @param enter_has_been_pressed : boolean to check if enter has been pressed
 *
 * @return std::unique_ptr<sf::RenderWindow> : the window
 */
    std::unique_ptr<sf::RenderWindow>
    View::draw_finished(std::unique_ptr<sf::RenderWindow> window, bool &enter_has_been_pressed) {
        window = finished_menu.draw(std::move(window));
        enter_has_been_pressed = finished_menu.update();

        return window;
    }

    std::unique_ptr<sf::RenderWindow>
    View::draw_dead(std::unique_ptr<sf::RenderWindow> window, bool &enter_has_been_pressed) {
        window = dead_menu.draw(std::move(window));
        enter_has_been_pressed = dead_menu.update();

        return window;
    }

}