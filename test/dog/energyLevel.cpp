#define BOOST_TEST_MODULE dog_energy_level
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <cmath>

#include "dog.hpp"

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