#define BOOST_TEST_MODULE dog_happiness
#include <boost/test/unit_test.hpp>

#include "dog.hpp"

BOOST_AUTO_TEST_SUITE(dog_happiness)

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

BOOST_AUTO_TEST_SUITE_END()