//
// Created by jarne on 1/5/23.
//

#include "Dead_menu.h"

std::unique_ptr<sf::RenderWindow> Game_representation::Dead_menu::draw(std::unique_ptr<sf::RenderWindow> window) {
    sf::Text text;
    sf::Text return_text;
    text.setFont(font);
    text.setString("You died!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 100);

    return_text.setFont(font);
    return_text.setString("Press enter to go back to the menu");
    return_text.setCharacterSize(24);
    return_text.setFillColor(sf::Color::White);
    return_text.setPosition(100, 200);

    window->draw(text);
    window->draw(return_text);

    return window;
}

bool Game_representation::Dead_menu::update() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
}
