//
// Created by jarne on 12/1/22.
//

#include "Finished_menu.h"
#include "../Values.cpp"

namespace Game_representation {

/**
 * @brief Draw the finished menu to the screen
 *
 * @param window : window to draw to
 *
 * @return std::unique_ptr<sf::RenderWindow> : the window
 */
    std::unique_ptr<sf::RenderWindow> Finished_menu::draw(std::unique_ptr<sf::RenderWindow> window) {
        sf::Text text;
        sf::Text menu_text;
        text.setFont(main_font);
        text.setString("You finished the level!");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(100, 100);

        menu_text.setFont(main_font);
        menu_text.setString("Press enter to go back to the menu");
        menu_text.setCharacterSize(24);
        menu_text.setFillColor(sf::Color::White);
        menu_text.setPosition(100, 200);

        window->draw(text);
        window->draw(menu_text);

        return window;
    }

/**
 * @brief update the finished menu (keypresses)
 *
 * @return true : if the enter key is pressed
 * @return false : if the enter key is not pressed
 */
    bool Finished_menu::update() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            return true;
        }
        return false;
    }

/**
 * @brief Construct a new Finished_menu::Finished_menu object
 *
 */
    Finished_menu::Finished_menu() {
        main_font.loadFromFile("Game_representation/assets/Debrosee.ttf");
    }

}