#include <SFML/Graphics.hpp>
#include "Game_representation/Game.h"
#include <memory>

#include "Stopwatch.h"

int main() {
    Stopwatch::getInstance()->start();
    std::shared_ptr<Game_representation::Game> game = std::make_shared<Game_representation::Game>();
    game->add_game_to_player_observer();
    game->loop();
    return 0;
}