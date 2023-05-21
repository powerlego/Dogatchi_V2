#define BOOST_TEST_MODULE dog_default_constructor
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <cmath>

#include "dog.hpp"

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