#ifndef NORK_PUBSUB_SUBSCRIBER_H
#define NORK_PUBSUB_SUBSCRIBER_H

namespace nork {

  template<typename T>
  class Publisher;

template<typename T>
class Subscriber {
  
private: 

  friend class Publisher<T>;
  virtual void on_event(T& event) = 0;
};

} // namespace nork

#endif // !NORK_PUBSUB_SUBSCRIBER_H
