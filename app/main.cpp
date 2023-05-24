#include <iostream>

#include "dog.hpp"

int main(int argc, char **argv) {
    Dog dog;
    std::cout << Dog::pupImage() << std::endl;
    dog.startTimer();
    while(1) {
        // do something
    }
}