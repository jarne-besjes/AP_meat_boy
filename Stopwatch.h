//
// Created by jarne on 11/15/22.
//

#ifndef MEAT_BOY_STOPWATCH_H
#define MEAT_BOY_STOPWATCH_H

// This is a singleton class
class Stopwatch {
    bool running = false;
    Stopwatch() = default;
public:
    Stopwatch &operator=(const Stopwatch &) = delete;
    Stopwatch(const Stopwatch &) = delete;

    static Stopwatch &getInstance();

    void start();
    void stop();
};


#endif //MEAT_BOY_STOPWATCH_H
