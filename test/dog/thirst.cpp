#define BOOST_TEST_MODULE dog_thirst
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <cmath>

#include "dog.hpp"

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