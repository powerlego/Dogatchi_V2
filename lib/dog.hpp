/**
 * @file dog.hpp
 * @author Nicholas Curl (curl.nicholas@gmail.com)
 * @brief Header file for the Dog class
 * @version 0.1
 * @date 05-24-2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>

#include "callbackTimer.hpp"

/**
 * @brief The Dog class
 *
 */
class Dog {
    public:
        /**
         * @brief Construct a new Dog object
         *
         */
        Dog();

        /**
         * @brief Construct a new Dog object
         *
         * @param name The name of the dog
         * @param weight The weight of the dog in pounds
         * @param age The age of the dog in months
         * @param hunger The hunger level of the dog
         * @param happiness The happiness level of the dog
         * @param energyLevel The energy level of the dog
         * @param thirst The thirst level of the dog
         */
        Dog(std::string name, int weight, int age, int hunger, int happiness, int energyLevel, int thirst);
        /**
         * @brief Destroy the Dog object
         *
         */
        virtual ~Dog();

        /**
         * @brief Get the Name object
         *
         * @return std::string The name of the dog
         */
        std::string getName() const;
        void        setName(std::string name);
        int         getWeight() const;
        void        setWeight(int weight);
        int         getAge() const;
        void        setAge(int age);
        int         getHunger() const;
        void        setHunger(int hunger);
        int         getHappiness() const;
        void        setHappiness(int happiness);
        int         getEnergyLevel() const;
        void        setEnergyLevel(int energyLevel);
        int         getThirst() const;
        void        setThirst(int thirst);
        void        startTimer();
        void        stopTimer();
        void        eat();
        void        drink();
        void        sleep();

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