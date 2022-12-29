//
// Created by jarne on 11/29/22.
//

#include "Level_selection.h"
#include <chrono>
#include <thread>

namespace Game_representation {

/**
 * @brief Construct a new Level_selection::Level_selection object
 *
 */
    Level_selection::Level_selection() {
        main_font.loadFromFile("Game_representation/assets/Freshman-POdx.ttf");
    }

/**
 * @brief Draw the level selection screen
 *
 * @param window : window to draw to
 * @param levels : vector of the possible levels to choose from
 *
 * @return std::unique_ptr<sf::RenderWindow> : the window
 */
    std::unique_ptr<sf::RenderWindow>
    Level_selection::draw(std::unique_ptr<sf::RenderWindow> window, const std::vector<std::string> &levels) {
        for (int i = 0; i < levels.size(); i++) {
            sf::Text text;
            text.setFont(main_font);
            text.setString(levels[i]);
            text.setCharacterSize(24);
            if (i == selected_level) {
                text.setFillColor(sf::Color::Red);
            } else {
                text.setFillColor(sf::Color::White);
            }
            text.setPosition(100, 100 + i * 50);
            window->draw(text);
        }

        return window;
    }

/**
 * @brief Update the level selection screen (keypresses)
 *
 * @param window : window to update
 * @param levels : vector of the possible levels to choose from
 * @param level : the level that is selected
 *
 * @return std::unique_ptr<sf::RenderWindow> : the window
 */
    std::unique_ptr<sf::RenderWindow>
    Level_selection::update(std::unique_ptr<sf::RenderWindow> window, const std::vector<std::string> &levels,
                            std::string &level)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        const int nr_of_levels = levels.size();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (selected_level > 0) {
                selected_level--;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (selected_level < nr_of_levels - 1) {
                selected_level++;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            level = levels[selected_level];
        }

        return window;
    }


}
