#define BOOST_TEST_MODULE dog_name
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <cmath>

#include "dog.hpp"

BOOST_AUTO_TEST_CASE(getName) {
    Dog dog;
    BOOST_TEST(dog.getName() == std::string("Dog"));
}

BOOST_AUTO_TEST_CASE(setName) {
    Dog dog;
    dog.setName("Nicholas");
    BOOST_TEST(dog.getName() == std::string("Nicholas"));
}