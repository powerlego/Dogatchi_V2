#define BOOST_TEST_MODULE dog_energy_level
#include <boost/test/unit_test.hpp>

#include "dog.hpp"

BOOST_AUTO_TEST_SUITE(dog_energy_level)

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

BOOST_AUTO_TEST_SUITE_END()