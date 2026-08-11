#pragma once

#include <etl/vector.h>
#include <functional>

template<typename... Args>
class Event {

private:
    etl::vector<std::function<void(Args...)>, 3> listeners;

public:

    Event() = default;

    void connect(
        const std::function<void(Args...)>& listener
    ){
        listeners.push_back(listener);
    }

    void broadcast(Args... args){
        for(auto& listener : listeners){
            listener(args...);
        }
    }
};