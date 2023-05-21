#define BOOST_TEST_MODULE dog_update
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <cmath>

#include "dog.hpp"

BOOST_AUTO_TEST_CASE(update) {
    Dog dog;
    dog.startTimer();
    boost::this_thread::sleep_for(boost::chrono::milliseconds(25000));
    dog.stopTimer();
    BOOST_TEST(dog.getAge() == 73);
    BOOST_TEST(fabs(dog.getWeight() - 100.005) <= std::numeric_limits<double>::epsilon());
    BOOST_TEST(fabs(dog.getHunger() - 99.95) <= std::numeric_limits<double>::epsilon());
    BOOST_TEST(fabs(dog.getHappiness() - 99.997) <= std::numeric_limits<double>::epsilon());
    BOOST_TEST(fabs(dog.getEnergyLevel() - 19.991) <= std::numeric_limits<double>::epsilon());
    BOOST_TEST(fabs(dog.getThirst() - 95) <= std::numeric_limits<double>::epsilon());
}