#define BOOST_TEST_MODULE dog_hunger
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <cmath>

#include "dog.hpp"

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