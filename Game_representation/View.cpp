//
// Created by jarne on 11/16/22.
//

#include "View.h"
#include "Game.h"
#include "../Game_logic/Blocks/Entity.h"
#include "../Values.cpp"

/**
 * @brief draw the menu to the game
 * 
 * @param window : window to draw the menu to
 * @param has_to_close : boolean to check if the game has to close
 * @return std::unique_ptr<sf::RenderWindow> : the window to draw the menu to
 */
std::unique_ptr<sf::RenderWindow> View::draw_menu(std::unique_ptr<sf::RenderWindow> window, bool &has_to_close) {
    // we have to reset our view, because we might have changed it in the level
    view.setCenter(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
    window->setView(view);
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
View::View(Game &game): game(game), menu(game) {
    view = sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
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

    view.setCenter(game.get_camera().get_x(), game.get_camera().get_y());
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

/**
 * @brief draw the entities to the game
 * 
 * @param window : window to draw the entities to
 * @param entities : entities to draw
 * 
 * @return std::unique_ptr<sf::RenderWindow> : the window
 */
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
View::draw_level_choice(std::unique_ptr<sf::RenderWindow> window, const std::vector<std::string> &levels, std::string &level) {
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
std::unique_ptr<sf::RenderWindow> View::draw_finished(std::unique_ptr<sf::RenderWindow> window, bool &enter_has_been_pressed) {
    window = finished_menu.draw(std::move(window));
    enter_has_been_pressed = finished_menu.update();

    return window;
}


