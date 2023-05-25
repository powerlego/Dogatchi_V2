/**
 * @file utils.cpp
 * @author Nicholas Curl (curl.nicholas@gmail.com)
 * @brief The source file for the utils library
 * @version 0.1
 * @date 05-25-2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "utils.hpp"

std::vector<std::string> split(std::string s, std::string delimiter) {
    std::vector<std::string> messages;
    size_t                   pos = 0;
    std::string              token;
    while((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        messages.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    return messages;
}