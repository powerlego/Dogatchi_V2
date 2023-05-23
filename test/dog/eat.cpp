#define BOOST_TEST_MODULE dog_eat
#include <boost/test/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>

#include "dog.hpp"
#include "utils.hpp"

BOOST_AUTO_TEST_SUITE(dog_eat)

BOOST_AUTO_TEST_CASE(eatStats) {
    Dog dog("Dog", 0, 0, 0, 0, 0, 0);
    dog.eat();
    BOOST_TEST(dog.getHunger() == 10);
    BOOST_TEST(dog.getHappiness() == 5);
    BOOST_TEST(dog.getEnergyLevel() == 5);
    BOOST_TEST(dog.getWeight() == 5);
}

BOOST_AUTO_TEST_CASE(eatMessages) {
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard(output.rdbuf());
        Dog           dog("Dog", 0, 0, 0, 0, 0, 0);
        dog.eat();
    }
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(messages[1] == "Dog is eating.");
    BOOST_TEST(messages[2] == "Dog is done eating.");
}

BOOST_AUTO_TEST_SUITE_END()