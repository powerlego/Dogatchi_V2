#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <vector>

struct cout_redirect {
        cout_redirect(std::streambuf *new_buffer) : old(std::cout.rdbuf(new_buffer)) {}
        ~cout_redirect() {
            std::cout.rdbuf(old);
        }

    private:
        std::streambuf *old;
};

extern std::vector<std::string> split(std::string str, std::string token);

#endif