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

Dog::Dog(std::string name, double weight, int age, double hunger, double happiness, double energyLevel, double thirst) {
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
    this->hunger -= 0.05;
    this->energyLevel -= 0.009;
    this->happiness -= 0.003;
    this->weight += 0.005;
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

double Dog::getWeight() const {
    return weight;
}

void Dog::setWeight(double weight) {
    this->weight = weight;
}

int Dog::getAge() const {
    return age;
}

void Dog::setAge(int age) {
    this->age = age;
}

double Dog::getHunger() const {
    return hunger;
}

void Dog::setHunger(double hunger) {
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

double Dog::getHappiness() const {
    return happiness;
}

void Dog::setHappiness(double happiness) {
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

double Dog::getEnergyLevel() const {
    return energyLevel;
}

void Dog::setEnergyLevel(double energyLevel) {
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

double Dog::getThirst() const {
    return thirst;
}

void Dog::setThirst(double thirst) {
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

Dog::~Dog() {
    timer.stop();
};