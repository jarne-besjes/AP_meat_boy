//
// Created by jarne on 11/21/22.
//

#ifndef MEAT_BOY_CAMERA_H
#define MEAT_BOY_CAMERA_H
#include "Values.cpp"


class Camera {

    // we always start the camera at the bottom of the screen
    const int x = 300; // x cant be changed
    int y;       // we only change the camera vertically
    // y = level size * 50 (blocks are 50x50) - 300

    int width = WINDOW_WIDTH;
    int height = WINDOW_HEIGHT;
public:

    bool enabled = false;

    Camera();

    void set_level_size(int level_y_size);

    int get_x() const;
    int get_y() const;
    int get_width() const;
    int get_height() const;

    void set_y(int y);

    void move_up(int amount);

};



#endif //MEAT_BOY_CAMERA_H
