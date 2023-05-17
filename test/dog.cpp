#define BOOST_TEST_MODULE dog
#include <boost/test/unit_test.hpp>

#include "dog.hpp"

BOOST_AUTO_TEST_SUITE(dog_suite)

BOOST_AUTO_TEST_CASE(dog_default_constructor) {
    Dog dog;
    BOOST_TEST(dog.getName() == std::string("Dog"));
    BOOST_TEST(dog.getAge() == 72);
    BOOST_TEST(dog.getWeight() == 100);
    BOOST_TEST(dog.getHunger() == 100);
    BOOST_TEST(dog.getHappiness() == 100);
    BOOST_TEST(dog.getEnergyLevel() == 20);
    BOOST_TEST(dog.getThirst() == 100);
}

BOOST_AUTO_TEST_CASE(dog_constructor) {
    Dog dog("Nicholas", 10, 1, 100, 100, 10, 100);
    BOOST_TEST(dog.getName() == std::string("Nicholas"));
    BOOST_TEST(dog.getAge() == 1);
    BOOST_TEST(dog.getWeight() == 10);
    BOOST_TEST(dog.getHunger() == 100);
    BOOST_TEST(dog.getHappiness() == 100);
    BOOST_TEST(dog.getEnergyLevel() == 10);
    BOOST_TEST(dog.getThirst() == 100);
}

BOOST_AUTO_TEST_SUITE_END()