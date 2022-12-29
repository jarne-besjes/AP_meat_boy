//
// Created by jarne on 11/19/22.
//

#ifndef MEAT_BOY_STATE_H
#define MEAT_BOY_STATE_H

namespace Game_representation {

    enum class Game_state {
        MENU,
        GAME,
        LEVEL_CHOICE,
        FINISHED
    };

    class State_manager {
        Game_state current_state;
    public:
        State_manager();

        Game_state get_state() const;

        void set_state(Game_state state);
    };

}


#endif //MEAT_BOY_STATE_H
