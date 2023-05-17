#include "callbackTimer.hpp"

CallbackTimer::CallbackTimer() : _execute(false) {}

CallbackTimer::~CallbackTimer() {
    if(_execute.load(std::memory_order_acquire)) {
        stop();
    }
}

void CallbackTimer::stop() {
    _execute.store(false, std::memory_order_release);
    if(_thd.joinable()) {
        _thd.join();
    }
}

void CallbackTimer::start(int interval, std::function<void(void)> func) {
    if(_execute.load(std::memory_order_acquire)) {
        stop();
    }
    _execute.store(true, std::memory_order_release);
    _thd = std::thread([this, interval, func]() {
        while(_execute.load(std::memory_order_acquire)) {
            func();
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }
    });
}

bool CallbackTimer::is_running() const noexcept {
    return (_execute.load(std::memory_order_acquire) && _thd.joinable());
}