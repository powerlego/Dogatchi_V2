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

#include <random>
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
         * @brief Get the name property
         *
         * @return std::string The name of the dog
         */
        std::string getName() const;
        /**
         * @brief Set the name property
         *
         * @param name The name of the dog
         */
        void        setName(std::string name);

        /**
         * @brief Get the weight property
         *
         * @return int The weight of the dog in pounds
         */
        int  getWeight() const;
        /**
         * @brief Set the weight property
         *
         * @param weight The weight of the dog in pounds
         */
        void setWeight(int weight);

        /**
         * @brief Get the age property
         *
         * @return int The age of the dog in months
         */
        int  getAge() const;
        /**
         * @brief Set the age property
         *
         * @param age The age of the dog in months
         */
        void setAge(int age);

        /**
         * @brief Get the hunger property
         *
         * @return int The hunger level of the dog
         */
        int  getHunger() const;
        /**
         * @brief Set the hunger property
         *
         * @param hunger The hunger level of the dog
         */
        void setHunger(int hunger);

        /**
         * @brief Get the happiness property
         *
         * @return int The happiness level of the dog
         */
        int  getHappiness() const;
        /**
         * @brief Set the happiness property
         *
         * @param happiness The happiness level of the dog
         */
        void setHappiness(int happiness);

        /**
         * @brief Get the energyLevel property
         *
         * @return int The energy level of the dog
         */
        int  getEnergyLevel() const;
        /**
         * @brief Set the energyLevel property
         *
         * @param energyLevel The energy level of the dog
         */
        void setEnergyLevel(int energyLevel);

        /**
         * @brief Get the thirst property
         *
         * @return int The thirst level of the dog
         */
        int  getThirst() const;
        /**
         * @brief Set the thirst property
         *
         * @param thirst The thirst level of the dog
         */
        void setThirst(int thirst);

        /**
         * @brief Start the update timer for the dog
         *
         */
        void startTimer();
        /**
         * @brief Stop the update timer for the dog
         *
         */
        void stopTimer();
        /**
         * @brief Let the dog eat
         *
         */
        void eat();
        /**
         * @brief Let the dog drink
         *
         */
        void drink();
        /**
         * @brief Let the dog sleep
         *
         */
        void sleep();

        /**
         * @brief Have the dog shake hands
         *
         */
        void shakeHands();
        /**
         * @brief Have the dog play dead
         *
         */
        void playDead();
        /**
         * @brief Have the dog pretend to be shot
         *
         */
        void bang();
        /**
         * @brief Have the dog roll over
         *
         */
        void rollOver();
        /**
         * @brief Have the dog bark
         *
         */
        void bark();
        /**
         * @brief Have the dog howl
         *
         */
        void howl();

        /**
         * @brief Have the dog fetch a bone
         *
         */
        void fetchBone();
        /**
         * @brief Have the dog fetch a stick
         *
         */
        void fetchStick();
        /**
         * @brief Have the dog fetch a ball
         *
         */
        void fetchBall();
        /**
         * @brief Have the dog fetch a frisbee
         *
         */
        void fetchFrisbee();
        /**
         * @brief Have the dog play tug-of-war
         *
         */
        void tugOfWar();
        /**
         * @brief Have the dog jump
         *
         */
        void jump();
        /**
         * @brief Have the dog jump a rope
         *
         */
        void jumpRope();
        /**
         * @brief Have the dog jump through a hoop
         *
         */
        void jumpThroughHoop();
        /**
         * @brief Have the dog jump over a fence
         *
         */
        void jumpOverFence();
        /**
         * @brief Have the dog spin in a circle
         *
         */
        void spin();
        /**
         * @brief Have the dog crawl on the ground
         *
         */
        void crawl();
        /**
         * @brief Have the dog sit
         *
         */
        void sit();
        /**
         * @brief Have the dog lay down
         *
         */
        void layDown();

        /**
         * @brief An ASCII image of a dog
         *
         * @return std::string The ASCII image of a dog
         */
        static std::string pupImage();

    private:
        /**
         * @brief The timer for updating the dog's properties
         *
         */
        CallbackTimer timer;
        /**
         * @brief The name of the dog
         *
         */
        std::string   name;
        /**
         * @brief The weight of the dog in pounds
         *
         */
        int           weight;
        /**
         * @brief The age of the dog in months
         *
         */
        int           age;
        /**
         * @brief The hunger level of the dog
         *
         */
        int           hunger;
        /**
         * @brief The happiness level of the dog
         *
         */
        int           happiness;
        /**
         * @brief The energy level of the dog
         *
         */
        int           energyLevel;
        /**
         * @brief The thirst level of the dog
         *
         */
        int           thirst;

        /**
         * @brief Random device for generating random numbers
         *
         */
        std::random_device rd;

        /**
         * @brief Function to update the dog's properties
         *
         */
        void update();
};

#endif