//
// Created by jarne on 11/15/22.
//

#include "Stopwatch.h"
#include <iostream>

/**
 * @brief Get the instance of the stopwatch (this will allways return the same instance)
 * 
 * @return Stopwatch& : the instance that's returned
 */
Stopwatch *Stopwatch::getInstance() {
    static Stopwatch instance;
    return &instance;
}

/**
 * @brief Starts the stopwatch
 */
void Stopwatch::start() {
    previous = std::chrono::system_clock::now();
    running = true;
}

/**
 * @brief returns the passed time since the previous frame
 */
double Stopwatch::elapsed() {
    if (!running) {
        throw std::runtime_error("Stopwatch is not running");
    }
    current = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = current - previous;
    return elapsed_seconds.count();
}

/**
 * @brief resets the stopwatch
 */
void Stopwatch::next_frame() {
    if (!running) {
        throw std::runtime_error("Stopwatch is not running");
    }
    current = std::chrono::system_clock::now();
    previous = current;
    current = std::chrono::system_clock::now();
}