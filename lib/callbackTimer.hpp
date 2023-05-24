#ifndef CALLBACK_TIMER_HPP
#define CALLBACK_TIMER_HPP

#if defined(_WIN32) || defined(_WIN64)
    #include <sdkddkver.h>
#endif

#include <atomic>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <chrono>
#include <functional>
#include <thread>

class CallbackTimer {
    public:
        CallbackTimer();
        virtual ~CallbackTimer();
        void stop();
        void start(int interval, std::function<void(void)> func);

    private:
        void execute(int interval, std::function<void(void)> func, boost::asio::steady_timer &timer);
        void executeInternal(int interval, std::function<void(void)> func, boost::asio::steady_timer &timer,
                             const boost::system::error_code &ec);
        std::atomic<bool>         _stop;
        std::thread               thd;
        boost::asio::io_context   context;
        boost::asio::steady_timer timer;
};

#endif // CALLBACK_TIMER_HPP