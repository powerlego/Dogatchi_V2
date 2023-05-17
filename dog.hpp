#ifndef DOG_HPP
#define DOG_HPP

#include <string>

#include "callbackTimer.hpp"

class Dog {
    public:
        Dog();
        Dog(std::string name, double weight, int age, double hunger, double happiness, double energyLevel,
            double thirst);
        virtual ~Dog();
        std::string        getName() const;
        void               setName(std::string name);
        double             getWeight() const;
        void               setWeight(double weight);
        int                getAge() const;
        void               setAge(int age);
        double             getHunger() const;
        void               setHunger(double hunger);
        double             getHappiness() const;
        void               setHappiness(double happiness);
        double             getEnergyLevel() const;
        void               setEnergyLevel(double energyLevel);
        double             getThirst() const;
        void               setThirst(double thirst);
        void               startTimer();
        void               stopTimer();
        static std::string pupImage();

    private:
        CallbackTimer timer;
        std::string   name;
        double        weight;
        int           age;
        double        hunger;
        double        happiness;
        double        energyLevel;
        double        thirst;

        void update();
};

#endif