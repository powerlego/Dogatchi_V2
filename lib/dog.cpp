/**
 * @file dog.cpp
 * @author Nicholas Curl (curl.nicholas@gmail.com)
 * @brief Source file for the Dog class
 * @version 0.1
 * @date 05-24-2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <boost/thread.hpp>
#include <chrono>
#include <iostream>
#include <random>

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
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done eating." << std::endl;
    hunger += 10;
    energyLevel += 5;
    happiness += 5;
    weight += 5;
}

void Dog::drink() {
    std::cout << name << " is drinking." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done drinking." << std::endl;
    thirst += 10;
    energyLevel += 5;
    happiness += 5;
}

void Dog::sleep() {
    std::cout << name << " is sleeping." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done sleeping." << std::endl;
    energyLevel += 10;
}

void Dog::shakeHands() {
    std::cout << name << " is shaking hands." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done shaking hands." << std::endl;
    happiness += 10;
    energyLevel -= 5;
    thirst -= 5;
    hunger -= 5;
}

void Dog::playDead() {
    std::cout << name << " is playing dead." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done playing dead." << std::endl;
    happiness += 10;
    energyLevel -= 5;
    thirst -= 5;
    hunger -= 5;
}

void Dog::bang() {
    std::cout << "You say the word bang to " << name << "." << std::endl;
    std::cout << name << " limps, then crawls, and then plays dead." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " stops doing the bang trick." << std::endl;
    happiness += 10;
    energyLevel -= 7;
    thirst -= 5;
    hunger -= 5;
}

void Dog::rollOver() {
    std::cout << name << " is rolling over." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done rolling over." << std::endl;
    happiness += 10;
    energyLevel -= 10;
    thirst -= 5;
    hunger -= 5;
}

void Dog::bark() {
    std::cout << name << " is barking." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done barking." << std::endl;
    happiness += 10;
    energyLevel -= 5;
    thirst -= 5;
    hunger -= 5;
}

void Dog::howl() {
    std::cout << name << " is howling." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done howling." << std::endl;
    happiness += 10;
    energyLevel -= 5;
    thirst -= 5;
    hunger -= 5;
}

void Dog::fetchBone() {
    std::cout << name << " is fetching a bone." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done fetching a bone." << std::endl;
    happiness += 10;
    energyLevel -= 10;
    thirst -= 10;
    hunger -= 10;
}

void Dog::fetchStick() {
    std::cout << name << " is fetching a stick." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done fetching a stick." << std::endl;
    happiness += 10;
    energyLevel -= 10;
    thirst -= 10;
    hunger -= 10;
}

void Dog::fetchBall() {
    std::cout << name << " is fetching a ball." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done fetching a ball." << std::endl;
    happiness += 10;
    energyLevel -= 10;
    thirst -= 10;
    hunger -= 10;
}

void Dog::fetchFrisbee() {
    std::cout << name << " is fetching a frisbee." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done fetching a frisbee." << std::endl;
    happiness += 10;
    energyLevel -= 10;
    thirst -= 10;
    hunger -= 10;
}

void Dog::tugOfWar() {
    std::random_device                 rd;
    std::default_random_engine         rng(rd());
    std::uniform_int_distribution<int> dist(0, 9);
    std::cout << "You pull on one side of the rope and " << name << " pulls on the other side." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    int random = dist(rng);
    if(random < 5) {
        std::cout << name << " won the game of tug of war." << std::endl;
        happiness += 10;
        energyLevel -= 10;
        thirst -= 10;
        hunger -= 10;
    }
    else {
        std::cout << name << " lost the game of tug of war." << std::endl;
        happiness -= 10;
        energyLevel -= 10;
        thirst -= 10;
        hunger -= 10;
    }
}

void Dog::jump() {
    std::cout << name << " is jumping." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done jumping." << std::endl;
    happiness += 10;
    energyLevel -= 10;
    thirst -= 10;
    hunger -= 10;
}

void Dog::jumpRope() {
    std::cout << name << " is jumping rope." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done jumping rope." << std::endl;
    happiness += 10;
    energyLevel -= 10;
    thirst -= 10;
    hunger -= 10;
}

void Dog::jumpThroughHoop() {
    std::cout << name << " is jumping through a hoop." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done jumping through a hoop." << std::endl;
    happiness += 10;
    energyLevel -= 10;
    thirst -= 10;
    hunger -= 10;
}

void Dog::jumpOverFence() {
    std::cout << name << " is jumping over a fence." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done jumping over a fence." << std::endl;
    happiness += 10;
    energyLevel -= 10;
    thirst -= 10;
    hunger -= 10;
}

void Dog::spin() {
    std::cout << name << " is spinning." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done spinning." << std::endl;
    happiness += 10;
    energyLevel -= 5;
    thirst -= 5;
    hunger -= 5;
}

void Dog::crawl() {
    std::cout << name << " is crawling." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done crawling." << std::endl;
    happiness += 10;
    energyLevel -= 5;
    thirst -= 5;
    hunger -= 5;
}

void Dog::sit() {
    std::cout << name << " is sitting." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done sitting." << std::endl;
    happiness += 5;
    thirst -= 5;
    hunger -= 5;
}

void Dog::layDown() {
    std::cout << name << " is laying down." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(2000));
    std::cout << name << " is done laying down." << std::endl;
    happiness += 5;
    energyLevel += 5;
    thirst -= 5;
    hunger -= 5;
}

Dog::~Dog() {
    timer.stop();
};