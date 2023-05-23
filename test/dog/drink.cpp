#define BOOST_TEST_MODULE dog_drink
#include <boost/test/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>

#include "dog.hpp"
#include "utils.hpp"

BOOST_AUTO_TEST_SUITE(dog_drink)

BOOST_AUTO_TEST_CASE(drinkStats) {
    Dog dog("Dog", 0, 0, 0, 0, 0, 0);
    dog.drink();
    BOOST_TEST(dog.getThirst() == 10);
    BOOST_TEST(dog.getHappiness() == 5);
    BOOST_TEST(dog.getEnergyLevel() == 5);
}

BOOST_AUTO_TEST_CASE(drinkMessages) {
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard(output.rdbuf());
        Dog           dog("Dog", 0, 0, 0, 0, 0, 0);
        dog.drink();
    }
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(messages[1] == "Dog is drinking.");
    BOOST_TEST(messages[2] == "Dog is done drinking.");
}

BOOST_AUTO_TEST_SUITE_END()