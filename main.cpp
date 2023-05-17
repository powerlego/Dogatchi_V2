#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

#include <iostream>

#include "dog.hpp"

int main(int argc, char **argv) {
#if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);
#endif

    Dog dog;
    std::cout << Dog::pupImage() << std::endl;
    while(1) {
        // do something
    }
}