#include <SFML/Graphics.hpp>
#include "Game_representation/Game.h"
#include <memory>

int main()
{
    std::shared_ptr<Game> game = std::make_shared<Game>();
    game->add_game_to_player_observer();
    game->loop();
    return 0;
}