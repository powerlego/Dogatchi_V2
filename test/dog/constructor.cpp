#define BOOST_TEST_MODULE dog_constructor
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <cmath>

#include "dog.hpp"

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