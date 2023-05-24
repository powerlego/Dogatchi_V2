#ifndef DOG_HPP
#define DOG_HPP

#include <string>

#include "callbackTimer.hpp"

class Dog {
    public:
        Dog();
        Dog(std::string name, int weight, int age, int hunger, int happiness, int energyLevel, int thirst);
        virtual ~Dog();
        std::string        getName() const;
        void               setName(std::string name);
        int                getWeight() const;
        void               setWeight(int weight);
        int                getAge() const;
        void               setAge(int age);
        int                getHunger() const;
        void               setHunger(int hunger);
        int                getHappiness() const;
        void               setHappiness(int happiness);
        int                getEnergyLevel() const;
        void               setEnergyLevel(int energyLevel);
        int                getThirst() const;
        void               setThirst(int thirst);
        void               startTimer();
        void               stopTimer();
        void               eat();
        void               drink();
        void               sleep();
        static std::string pupImage();

    private:
        CallbackTimer timer;
        std::string   name;
        int           weight;
        int           age;
        int           hunger;
        int           happiness;
        int           energyLevel;
        int           thirst;

        void update();
};

#endif