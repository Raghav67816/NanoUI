#pragma once

#include <vector>
#include <functional>

template<typename... Args>
class Event {

private:
    std::vector<std::function<void(Args...)>> listeners;

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