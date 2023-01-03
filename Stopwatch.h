//
// Created by jarne on 11/15/22.
//

#ifndef MEAT_BOY_STOPWATCH_H
#define MEAT_BOY_STOPWATCH_H

#include <chrono>

// This is a singleton class
class Stopwatch {
    bool running = false;
    Stopwatch() = default;
public:
    Stopwatch &operator=(const Stopwatch &) = delete;
    Stopwatch(const Stopwatch &) = delete;

    std::chrono::system_clock::time_point previous;
    std::chrono::system_clock::time_point current;

    static Stopwatch *getInstance();

    void start();
    double elapsed();
    void next_frame();
};


#endif //MEAT_BOY_STOPWATCH_H
