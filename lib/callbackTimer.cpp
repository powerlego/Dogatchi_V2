#include <iostream>

#include "callbackTimer.hpp"

CallbackTimer::CallbackTimer() : _stop(true), timer(context) {}

CallbackTimer::~CallbackTimer() {
    if(!_stop.load()) {
        stop();
    }
};

void CallbackTimer::stop() {
    _stop.store(true);
    timer.cancel();
    if(thd.joinable()) {
        thd.join();
    }
}

void CallbackTimer::execute(int interval, std::function<void(void)> func, boost::asio::steady_timer &timer) {
    timer.expires_after(std::chrono::milliseconds(interval));
    timer.async_wait([this, interval, func, &timer](const boost::system::error_code &ec) {
        executeInternal(interval, func, timer, ec);
    });
}

void CallbackTimer::executeInternal(int interval, std::function<void(void)> func, boost::asio::steady_timer &timer,
                                    const boost::system::error_code &ec) {
    if(_stop.load()) {
        return;
    }
    if(ec) {
        std::cout << "timer is canceled: " << ec << std::endl;
        return;
    }
    func();

    execute(interval, func, timer);
}

void CallbackTimer::start(int interval, std::function<void(void)> func) {
    if(!_stop.load()) {
        stop();
    }

    _stop.store(false);

    execute(interval, func, timer);

    thd = std::thread([this]() {
        context.run();
    });
}