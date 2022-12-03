//
// Created by jarne on 12/1/22.
//

#include "Finished_menu.h"

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

bool Finished_menu::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        return true;
    }
    return false;
}

Finished_menu::Finished_menu() {
    main_font.loadFromFile("Game_representation/assets/Debrosee.ttf");
}
