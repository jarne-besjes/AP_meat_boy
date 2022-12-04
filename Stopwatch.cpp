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
Stopwatch &Stopwatch::getInstance() {
    static Stopwatch instance;
    return instance;
}

/**
 * @brief Starts the stopwatch
 */
void Stopwatch::start() {
    current = std::chrono::system_clock::now();
}

/**
 * @brief Stops the stopwatch and saves the time difference
 */
void Stopwatch::stop() {
    previous = current;
    current = std::chrono::system_clock::now();
    diff = std::chrono::duration_cast<std::chrono::milliseconds>(current - previous).count();
}
