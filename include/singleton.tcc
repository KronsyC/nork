#ifndef NORK_SINGLETON_H
#define NORK_SINGLETON_H

namespace nork {
template <typename T> class Singleton {
    static T instance;
    static bool initialized;

  public:
    static T& get() {
        if (!initialized) {
            instance = T::T();
            initialized = true;
        }
        return &instance;
    }
};
template<typename T>
static Singleton<T>::initialized = false;
} // namespace nork



#endif // !NORK_SINGLETON_H
