/**
 * @file utils.hpp
 * @author Nicholas Curl (curl.nicholas@gmail.com)
 * @brief The header file for the utils library
 * @version 0.1
 * @date 05-25-2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Allows to redirect the std::cout to a buffer of your choice
 *
 */
struct cout_redirect {
        /**
         * @brief Construct a new cout redirect object
         *
         * @param new_buffer The buffer to redirect to
         */
        cout_redirect(std::streambuf *new_buffer) : old(std::cout.rdbuf(new_buffer)) {}

        /**
         * @brief Destroy the cout redirect object
         *
         */
        ~cout_redirect() {
            std::cout.rdbuf(old);
        }

    private:
        /**
         * @brief The old buffer
         *
         */
        std::streambuf *old;
};

/**
 * @brief Split a string into a vector of strings
 *
 * @param str The string to split
 * @param token The token to split the string with
 * @return std::vector<std::string> The vector of strings
 */
extern std::vector<std::string> split(std::string str, std::string token);

#endif