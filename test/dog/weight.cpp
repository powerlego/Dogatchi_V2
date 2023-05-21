#define BOOST_TEST_MODULE dog_weight
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <cmath>

#include "dog.hpp"

BOOST_AUTO_TEST_CASE(getWeight) {
    Dog dog;
    BOOST_TEST(dog.getWeight() == 100);
}

BOOST_AUTO_TEST_CASE(setWeight) {
    Dog dog;
    dog.setWeight(10);
    BOOST_TEST(dog.getWeight() == 10);
}