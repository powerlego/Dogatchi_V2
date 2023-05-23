#define BOOST_TEST_MODULE dog_update
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>

#include "dog.hpp"

BOOST_AUTO_TEST_CASE(update) {
    Dog dog;
    dog.startTimer();
    boost::this_thread::sleep_for(boost::chrono::milliseconds(25000));
    dog.stopTimer();
    BOOST_TEST(dog.getAge() == 73);
    BOOST_TEST(dog.getWeight() == 110);
    BOOST_TEST(dog.getHunger() == 90);
    BOOST_TEST(dog.getHappiness() == 95);
    BOOST_TEST(dog.getEnergyLevel() == 15);
    BOOST_TEST(dog.getThirst() == 95);
}