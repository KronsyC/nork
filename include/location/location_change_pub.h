#ifndef NORK_LOCATION_CHANGE_PUB_H
#define NORK_LOCATION_CHANGE_PUB_H

#include <iostream>
#include <memory>
#include <pubsub/publisher.h>
#include <string>
namespace nork {

struct LocationChangeEvent {
    std::string new_location_id;

    LocationChangeEvent(std::string lid) : new_location_id(lid) {}
};

// Globally available Location Change Publisher singleton
class LocationChangePublisher : public Publisher<LocationChangeEvent> {
    static std::unique_ptr<LocationChangePublisher> instance;

    LocationChangePublisher() : Publisher<LocationChangeEvent>() {}

  public:
    static LocationChangePublisher& get() {
        std::cout << "Get Instance" << std::endl;
        if (instance == nullptr) {
            std::cout << "Create" << std::endl;
            instance = std::unique_ptr<LocationChangePublisher>(new LocationChangePublisher());
            // Initialize the publisher
        }
        return *instance.get();
    }
};
} // namespace nork

#endif
