#include <boost/thread.hpp>
#include <chrono>
#include <iostream>

#include "dog.hpp"

Dog::Dog() {
    name        = "Dog";
    weight      = 100;
    age         = 72;
    hunger      = 100;
    happiness   = 100;
    energyLevel = 20;
    thirst      = 100;
}

Dog::Dog(std::string name, int weight, int age, int hunger, int happiness, int energyLevel, int thirst) {
    this->name        = name;
    this->weight      = weight;
    this->age         = age;
    this->hunger      = hunger;
    this->happiness   = happiness;
    this->energyLevel = energyLevel;
    this->thirst      = thirst;
    std::cout << "A new dog named " << name << " has been born." << std::endl;
}

void Dog::startTimer() {
    timer.start(25000, [this]() {
        update();
    });
}

void Dog::stopTimer() {
    timer.stop();
}

void Dog::update() {
    this->age += 1;
    this->hunger -= 10;
    this->energyLevel -= 5;
    this->happiness -= 5;
    this->weight += 10;
    this->thirst -= 5;
}

std::string Dog::pupImage() {
    return "   _=,_\no_/6 /#\\\n\\__ |##/\n ='|--\\\n   /   #'-.\n   \\#|_   _'-. /\n    |/ \\_( # |\" \n   C/ ,--___/";
}

std::string Dog::getName() const {
    return name;
}

void Dog::setName(std::string name) {
    this->name = name;
}

int Dog::getWeight() const {
    return weight;
}

void Dog::setWeight(int weight) {
    this->weight = weight;
}

int Dog::getAge() const {
    return age;
}

void Dog::setAge(int age) {
    this->age = age;
}

int Dog::getHunger() const {
    return hunger;
}

void Dog::setHunger(int hunger) {
    if(hunger > 100) {
        this->hunger = 100;
    }
    else if(hunger < 0) {
        this->hunger = 0;
    }
    else {
        this->hunger = hunger;
    }
}

int Dog::getHappiness() const {
    return happiness;
}

void Dog::setHappiness(int happiness) {
    if(happiness > 100) {
        this->happiness = 100;
    }
    else if(happiness < 0) {
        this->happiness = 0;
    }
    else {
        this->happiness = happiness;
    }
}

int Dog::getEnergyLevel() const {
    return energyLevel;
}

void Dog::setEnergyLevel(int energyLevel) {
    if(energyLevel > 100) {
        this->energyLevel = 100;
    }
    else if(energyLevel < 0) {
        this->energyLevel = 0;
    }
    else {
        this->energyLevel = energyLevel;
    }
}

int Dog::getThirst() const {
    return thirst;
}

void Dog::setThirst(int thirst) {
    if(thirst > 100) {
        this->thirst = 100;
    }
    else if(thirst < 0) {
        this->thirst = 0;
    }
    else {
        this->thirst = thirst;
    }
}

void Dog::eat() {
    std::cout << name << " is eating." << std::endl;
    hunger += 10;
    energyLevel += 5;
    happiness += 5;
    weight += 5;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done eating." << std::endl;
}

void Dog::drink() {
    std::cout << name << " is drinking." << std::endl;
    thirst += 10;
    energyLevel += 5;
    happiness += 5;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done drinking." << std::endl;
}

void Dog::sleep() {
    std::cout << name << " is sleeping." << std::endl;
    energyLevel += 10;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done sleeping." << std::endl;
}

Dog::~Dog() {
    timer.stop();
};