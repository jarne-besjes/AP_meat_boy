//
// Created by jarne on 11/21/22.
//

#ifndef MEAT_BOY_CAMERA_H
#define MEAT_BOY_CAMERA_H
#include "Values.cpp"
#include "Game_logic/Blocks/Entity.h"
#include <memory>
#include "Game_logic/Player.h"

class Camera {

    // we always start the camera at the bottom of the screen
    const int x = 300; // x cant be changed
    float y;       // we only change the camera vertically
    // y = level size * 50 (blocks are 50x50) - 300

    int width = WINDOW_WIDTH;
    int height = WINDOW_HEIGHT;
    double bottom_y = 0;
    double top_y = 0;
public:
    // TODO: find out the level bounds and set the y coordinate accordingly in the get_visible entities function

    bool enabled = false;

    Camera();

    void set_level_size(int level_y_size);

    float get_x() const;

    float get_y() const;

    float get_width() const;

    float get_height() const;

    void set_y(float y);

    void move_up(float amount);

    void get_visible_entities(std::vector<std::shared_ptr<Game_logic::Entity>> &entities) const;

    static void clear_visible_entities(std::vector<std::shared_ptr<Game_logic::Entity>> &entities);

    void project_entities(std::vector<std::shared_ptr<Game_logic::Entity>> &entities);

    void project_player(Game_logic::Player &player);
};



#endif //MEAT_BOY_CAMERA_H
