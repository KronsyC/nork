#ifndef NORK_PUBSUB_PUBLISHER_H
#define NORK_PUBSUB_PUBLISHER_H

#include "subscriber.h"
#include <algorithm>
#include <vector>
#include<iostream>
namespace nork {

template <typename T> class Publisher {

  public:
    Publisher() { this->subscribers = std::vector<Subscriber<T>*>(); }

  private:
    std::vector<Subscriber<T>*> subscribers;

  public:
    void publish(T event) {
        for (auto s : this->subscribers) {
            s->on_event(event);
        }
    }

    void register_listener(Subscriber<T>* sub) { this->subscribers.push_back(sub); }

    void remove_listener(Subscriber<T>* sub) { this->subscribers.erase(std::find(subscribers.begin(), subscribers.end(), sub)); }
};

} // namespace nork

#endif // !NORK_PUBSUB_PUBLISHER_H
