//
// Created by jarne on 11/15/22.
//

#include "Observer.h"

void IObservable::register_observer(std::shared_ptr<IObserver> observer) {
    observers.push_back(observer);
}

void IObservable::remove_observer(std::shared_ptr<IObserver> observer) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) {
            observers.erase(it);
            break;
        }
    }
}

void IObservable::notify_observers() {
    for (auto &observer : observers) {
        observer->update();
    }
}
