//
// Created by jarne on 11/13/22.
//

#include "Main_menu.h"
#include <iostream>

#include "Game.h"

Main_menu::Main_menu(Game &game): game(game) {
    main_font.loadFromFile("Game_representation/assets/Debrosee.ttf");
}

void Main_menu::draw() {
    game_title.setFont(main_font);
    game_title.setString("Meat Boy");
    game_title.setOrigin(game_title.getLocalBounds().width / 2, game_title.getLocalBounds().height / 2);
    game_title.setPosition(400, 100);
    game_title.setScale(2, 2);

    play_button.setFont(main_font);
    play_button.setString("Play");
    play_button.setOrigin(play_button.getLocalBounds().width / 2, play_button.getLocalBounds().height / 2);
    play_button.setPosition(400, 300);
    play_button.setScale(2, 2);
    if (play_button_selected) {
        play_button.setFillColor(sf::Color::Red);
    } else {
        play_button.setFillColor(sf::Color::White);
    }

    quit_button.setFont(main_font);
    quit_button.setString("Quit");
    quit_button.setOrigin(quit_button.getLocalBounds().width / 2, quit_button.getLocalBounds().height / 2);
    quit_button.setPosition(400, 400);
    quit_button.setScale(2, 2);
    if (quit_button_selected) {
        quit_button.setFillColor(sf::Color::Red);
    } else {
        quit_button.setFillColor(sf::Color::White);
    }
}

void Main_menu::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (play_button_selected) {
            play_button_selected = false;
            quit_button_selected = true;
        } else if (quit_button_selected) {
            quit_button_selected = false;
            play_button_selected = true;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (play_button_selected) {
            play_button_selected = false;
            quit_button_selected = true;
        } else if (quit_button_selected) {
            quit_button_selected = false;
            play_button_selected = true;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        if (play_button_selected) {
            game.play_button_pressed();
        } else if (quit_button_selected) {
            game.close_window();
        }
    }
}

std::unique_ptr<sf::RenderWindow> Main_menu::display(std::unique_ptr<sf::RenderWindow> window) {
    window->draw(game_title);
    window->draw(play_button);
    window->draw(quit_button);

    return window;
}
