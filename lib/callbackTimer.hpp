/**
 * @file callbackTimer.hpp
 * @author Nicholas Curl (curl.nicholas@gmail.com)
 * @brief Class to represent a CallbackTimer
 * @version 0.1
 * @date 05-24-2023
 *
 * @copyright Copyright (c) 2023
 *
 */
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

/**
 * @brief Class to represent a CallbackTimer
 *
 */
class CallbackTimer {
    public:
        /**
         * @brief Construct a new CallbackTimer object
         *
         */
        CallbackTimer();
        /**
         * @brief Destroy the CallbackTimer object
         *
         */
        virtual ~CallbackTimer();

        /**
         * @brief Stop the timer
         *
         */
        void stop();

        /**
         * @brief Start the timer
         *
         * @param interval The interval in milliseconds
         * @param func The function to call
         */
        void start(int interval, std::function<void(void)> func);

    private:
        /**
         * @brief Execute the timer asynchronously
         *
         * @param interval The interval in milliseconds
         * @param func The function to call
         * @param timer The timer object
         */
        void execute(int interval, std::function<void(void)> func, boost::asio::steady_timer &timer);

        /**
         * @brief Execute the body of the timer
         *
         * @param interval The interval in milliseconds
         * @param func The function to call
         * @param timer The timer object
         * @param ec The error code
         */
        void executeInternal(int interval, std::function<void(void)> func, boost::asio::steady_timer &timer,
                             const boost::system::error_code &ec);

        /**
         * @brief The stop flag
         *
         */
        std::atomic<bool> _stop;

        /**
         * @brief The thread to run the timer
         *
         */
        std::thread thd;

        /**
         * @brief The io context for the timer
         *
         */
        boost::asio::io_context context;

        /**
         * @brief The timer object itself
         *
         */
        boost::asio::steady_timer timer;
};

#endif // CALLBACK_TIMER_HPP