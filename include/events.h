#ifndef NORK_EVENTS_H
#define NORK_EVENTS_H

#include <iostream>
#include <memory>
#include <pubsub/publisher.h>
#include <string>
namespace nork {

struct LocationChangeEvent {
    std::string new_location_id;

    LocationChangeEvent(std::string lid) : new_location_id(lid) {}
};

struct DuckClaimEvent {
    uint16_t instance_id;
};

// Globally available Location Change Publisher singleton
class LocationChangePublisher : public Publisher<LocationChangeEvent> {
    static std::unique_ptr<LocationChangePublisher> instance;

    LocationChangePublisher() : Publisher<LocationChangeEvent>() {}

  public:
    static LocationChangePublisher& get() {
        if (instance == nullptr) {
            instance = std::unique_ptr<LocationChangePublisher>(new LocationChangePublisher());
            // Initialize the publisher
        }
        return *instance.get();
    }
};

// Globally available Duck Claim Publisher singleton
class DuckClaimPublisher : public Publisher<DuckClaimEvent> {
    static std::unique_ptr<DuckClaimPublisher> instance;

    DuckClaimPublisher() : Publisher<DuckClaimEvent>() {}

  public:
    static DuckClaimPublisher& get() {
        if (instance == nullptr) {
            instance = std::unique_ptr<DuckClaimPublisher>(new DuckClaimPublisher());
            // Initialize the publisher
        }
        return *instance.get();
    }
};
} // namespace nork

#endif
