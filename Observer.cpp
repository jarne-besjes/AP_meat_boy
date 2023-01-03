//
// Created by jarne on 11/15/22.
//

#include "Observer.h"

/**
 * @brief Registers an observer to the observable subject
 * 
 * @param observer : The object (that must derive from IObserver) to register
 */
void IObservable::register_observer(std::shared_ptr<IObserver> observer) {
    observers.push_back(observer);
}

/**
 * @brief Removes an observer from the observable subject
 * 
 * @param observer : The object (that must derive from IObserver) to remove
 */
void IObservable::remove_observer(std::shared_ptr<IObserver> observer) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) {
            observers.erase(it);
            break;
        }
    }
}

/**
 * @brief Notifies all observers of the observable subject
 */
void IObservable::notify_observers() {
    for (auto &observer: observers) {
        observer->update();
    }
}
