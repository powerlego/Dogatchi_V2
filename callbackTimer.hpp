#ifndef CALLBACK_TIMER_HPP
#define CALLBACK_TIMER_HPP

#include <atomic>
#include <chrono>
#include <functional>
#include <thread>

class CallbackTimer {
    public:
        CallbackTimer();
        virtual ~CallbackTimer();
        void stop();
        void start(int interval, std::function<void(void)> func);
        bool is_running() const noexcept;

    private:
        std::atomic<bool> _execute;
        std::thread       _thd;
};

#endif // CALLBACK_TIMER_HPP