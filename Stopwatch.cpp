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
    std::cout << "Stopwatch: " << this << "started" << std::endl;
}

void Stopwatch::stop() {
    std::cout << "Stopwatch: " << this << "stopped" << std::endl;
}
