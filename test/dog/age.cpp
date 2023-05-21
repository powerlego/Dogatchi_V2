#define BOOST_TEST_MODULE dog_age
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <cmath>

#include "dog.hpp"

BOOST_AUTO_TEST_CASE(getAge) {
    Dog dog;
    BOOST_TEST(dog.getAge() == 72);
}

BOOST_AUTO_TEST_CASE(setAge) {
    Dog dog;
    dog.setAge(1);
    BOOST_TEST(dog.getAge() == 1);
}