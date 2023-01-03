//
// Created by jarne on 11/15/22.
//

#ifndef MEAT_BOY_OBSERVER_H
#define MEAT_BOY_OBSERVER_H

#include <vector>
#include <memory>

class IObserver {
public:
    virtual void update() = 0;
};


class IObservable {
    std::vector<std::shared_ptr<IObserver>> observers;

public:
    virtual void remove_observer(std::shared_ptr<IObserver> observer);

    virtual void notify_observers();

    virtual void register_observer(std::shared_ptr<IObserver> observer);

    virtual ~IObservable() = default;
};


#endif //MEAT_BOY_OBSERVER_H
