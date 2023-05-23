#define BOOST_TEST_MODULE dog_sleep
#include <boost/test/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

#include "dog.hpp"
#include "utils.hpp"

BOOST_AUTO_TEST_SUITE(dog_sleep)

BOOST_AUTO_TEST_CASE(sleepStats) {
    Dog dog("Dog", 0, 0, 0, 0, 0, 0);
    dog.sleep();
    BOOST_TEST(dog.getEnergyLevel() == 10);
}

BOOST_AUTO_TEST_CASE(sleepMessages) {
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard(output.rdbuf());
        Dog           dog("Dog", 0, 0, 0, 0, 0, 0);
        dog.sleep();
    }
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(messages[1] == "Dog is sleeping.");
    BOOST_TEST(messages[2] == "Dog is done sleeping.");
}

BOOST_AUTO_TEST_SUITE_END()