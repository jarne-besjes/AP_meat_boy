//
// Created by jarne on 11/15/22.
//

#include "Stopwatch.h"
#include <iostream>

Stopwatch &Stopwatch::getInstance() {
    static Stopwatch instance;
    return instance;
}

void Stopwatch::start() {
    current = std::chrono::system_clock::now();
}

void Stopwatch::stop() {
    previous = current;
    current = std::chrono::system_clock::now();
    diff = std::chrono::duration_cast<std::chrono::milliseconds>(current - previous).count();
}
