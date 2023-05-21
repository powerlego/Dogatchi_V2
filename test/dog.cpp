#define BOOST_TEST_MODULE dog
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <cmath>

#include "dog.hpp"
namespace DogTest {
    BOOST_AUTO_TEST_SUITE(dog_suite)

    BOOST_AUTO_TEST_CASE(default_constructor) {
        Dog dog;
        BOOST_TEST(dog.getName() == std::string("Dog"));
        BOOST_TEST(dog.getAge() == 72);
        BOOST_TEST(dog.getWeight() == 100);
        BOOST_TEST(dog.getHunger() == 100);
        BOOST_TEST(dog.getHappiness() == 100);
        BOOST_TEST(dog.getEnergyLevel() == 20);
        BOOST_TEST(dog.getThirst() == 100);
    }

    BOOST_AUTO_TEST_CASE(constructor) {
        Dog dog("Nicholas", 10, 1, 100, 100, 10, 100);
        BOOST_TEST(dog.getName() == std::string("Nicholas"));
        BOOST_TEST(dog.getAge() == 1);
        BOOST_TEST(dog.getWeight() == 10);
        BOOST_TEST(dog.getHunger() == 100);
        BOOST_TEST(dog.getHappiness() == 100);
        BOOST_TEST(dog.getEnergyLevel() == 10);
        BOOST_TEST(dog.getThirst() == 100);
    }

    BOOST_AUTO_TEST_CASE(pupImage) {
        BOOST_TEST(
            "   _=,_\no_/6 /#\\\n\\__ |##/\n ='|--\\\n   /   #'-.\n   \\#|_   _'-. /\n    |/ \\_( # |\" \n   C/ ,--___/"
            == Dog::pupImage());
    }

    BOOST_AUTO_TEST_CASE(getName) {
        Dog dog;
        BOOST_TEST(dog.getName() == std::string("Dog"));
    }

    BOOST_AUTO_TEST_CASE(setName) {
        Dog dog;
        dog.setName("Nicholas");
        BOOST_TEST(dog.getName() == std::string("Nicholas"));
    }

    BOOST_AUTO_TEST_CASE(getWeight) {
        Dog dog;
        BOOST_TEST(dog.getWeight() == 100);
    }

    BOOST_AUTO_TEST_CASE(setWeight) {
        Dog dog;
        dog.setWeight(10);
        BOOST_TEST(dog.getWeight() == 10);
    }

    BOOST_AUTO_TEST_CASE(getAge) {
        Dog dog;
        BOOST_TEST(dog.getAge() == 72);
    }

    BOOST_AUTO_TEST_CASE(setAge) {
        Dog dog;
        dog.setAge(1);
        BOOST_TEST(dog.getAge() == 1);
    }

    BOOST_AUTO_TEST_CASE(getHunger) {
        Dog dog;
        BOOST_TEST(dog.getHunger() == 100);
    }

    BOOST_AUTO_TEST_CASE(setHunger) {
        Dog dog;
        dog.setHunger(50);
        BOOST_TEST(dog.getHunger() == 50);
        dog.setHunger(200);
        BOOST_TEST(dog.getHunger() == 100);
        dog.setHunger(-200);
        BOOST_TEST(dog.getHunger() == 0);
    }

    BOOST_AUTO_TEST_CASE(getHappiness) {
        Dog dog;
        BOOST_TEST(dog.getHappiness() == 100);
    }

    BOOST_AUTO_TEST_CASE(setHappiness) {
        Dog dog;
        dog.setHappiness(50);
        BOOST_TEST(dog.getHappiness() == 50);
        dog.setHappiness(200);
        BOOST_TEST(dog.getHappiness() == 100);
        dog.setHappiness(-200);
        BOOST_TEST(dog.getHappiness() == 0);
    }

    BOOST_AUTO_TEST_CASE(getEnergyLevel) {
        Dog dog;
        BOOST_TEST(dog.getEnergyLevel() == 20);
    }

    BOOST_AUTO_TEST_CASE(setEnergyLevel) {
        Dog dog;
        dog.setEnergyLevel(50);
        BOOST_TEST(dog.getEnergyLevel() == 50);
        dog.setEnergyLevel(200);
        BOOST_TEST(dog.getEnergyLevel() == 100);
        dog.setEnergyLevel(-200);
        BOOST_TEST(dog.getEnergyLevel() == 0);
    }

    BOOST_AUTO_TEST_CASE(getThirst) {
        Dog dog;
        BOOST_TEST(dog.getThirst() == 100);
    }

    BOOST_AUTO_TEST_CASE(setThirst) {
        Dog dog;
        dog.setThirst(50);
        BOOST_TEST(dog.getThirst() == 50);
        dog.setThirst(200);
        BOOST_TEST(dog.getThirst() == 100);
        dog.setThirst(-200);
        BOOST_TEST(dog.getThirst() == 0);
    }

    BOOST_AUTO_TEST_CASE(update) {
        Dog dog;
        dog.startTimer();
        boost::this_thread::sleep_for(boost::chrono::milliseconds(12500));
        dog.stopTimer();
        BOOST_TEST(dog.getAge() == 73);
        BOOST_TEST(fabs(dog.getWeight() - 100.005) <= std::numeric_limits<double>::epsilon());
        BOOST_TEST(fabs(dog.getHunger() - 99.95) <= std::numeric_limits<double>::epsilon());
        BOOST_TEST(fabs(dog.getHappiness() - 99.997) <= std::numeric_limits<double>::epsilon());
        BOOST_TEST(fabs(dog.getEnergyLevel() - 19.991) <= std::numeric_limits<double>::epsilon());
        BOOST_TEST(fabs(dog.getThirst() - 95) <= std::numeric_limits<double>::epsilon());
    }

    BOOST_AUTO_TEST_SUITE_END()
 } // namespace DogTest