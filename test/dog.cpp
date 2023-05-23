#define BOOST_TEST_MODULE dog
#include <boost/test/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>

#include "dog.hpp"
#include "utils.hpp"

BOOST_AUTO_TEST_SUITE(DogTests)

BOOST_AUTO_TEST_CASE(Constructor) {
    Dog dog("Nicholas", 10, 1, 100, 100, 10, 100);
    BOOST_TEST(dog.getName() == std::string("Nicholas"));
    BOOST_TEST(dog.getAge() == 1);
    BOOST_TEST(dog.getWeight() == 10);
    BOOST_TEST(dog.getHunger() == 100);
    BOOST_TEST(dog.getHappiness() == 100);
    BOOST_TEST(dog.getEnergyLevel() == 10);
    BOOST_TEST(dog.getThirst() == 100);
}

BOOST_AUTO_TEST_CASE(DefaultConstructor) {
    Dog dog;
    BOOST_TEST(dog.getName() == std::string("Dog"));
    BOOST_TEST(dog.getAge() == 72);
    BOOST_TEST(dog.getWeight() == 100);
    BOOST_TEST(dog.getHunger() == 100);
    BOOST_TEST(dog.getHappiness() == 100);
    BOOST_TEST(dog.getEnergyLevel() == 20);
    BOOST_TEST(dog.getThirst() == 100);
}

BOOST_AUTO_TEST_CASE(GetName) {
    Dog dog;
    BOOST_TEST(dog.getName() == std::string("Dog"));
}

BOOST_AUTO_TEST_CASE(SetName) {
    Dog dog;
    dog.setName("Nicholas");
    BOOST_TEST(dog.getName() == std::string("Nicholas"));
}

BOOST_AUTO_TEST_CASE(GetAge) {
    Dog dog;
    BOOST_TEST(dog.getAge() == 72);
}

BOOST_AUTO_TEST_CASE(SetAge) {
    Dog dog;
    dog.setAge(1);
    BOOST_TEST(dog.getAge() == 1);
}

BOOST_AUTO_TEST_CASE(GetHunger) {
    Dog dog;
    BOOST_TEST(dog.getHunger() == 100);
}

BOOST_AUTO_TEST_CASE(SetHunger) {
    Dog dog;
    dog.setHunger(50);
    BOOST_TEST(dog.getHunger() == 50);
    dog.setHunger(200);
    BOOST_TEST(dog.getHunger() == 100);
    dog.setHunger(-200);
    BOOST_TEST(dog.getHunger() == 0);
}

BOOST_AUTO_TEST_CASE(GetHappiness) {
    Dog dog;
    BOOST_TEST(dog.getHappiness() == 100);
}

BOOST_AUTO_TEST_CASE(SetHappiness) {
    Dog dog;
    dog.setHappiness(50);
    BOOST_TEST(dog.getHappiness() == 50);
    dog.setHappiness(200);
    BOOST_TEST(dog.getHappiness() == 100);
    dog.setHappiness(-200);
    BOOST_TEST(dog.getHappiness() == 0);
}

BOOST_AUTO_TEST_CASE(GetEnergyLevel) {
    Dog dog;
    BOOST_TEST(dog.getEnergyLevel() == 20);
}

BOOST_AUTO_TEST_CASE(SetEnergyLevel) {
    Dog dog;
    dog.setEnergyLevel(50);
    BOOST_TEST(dog.getEnergyLevel() == 50);
    dog.setEnergyLevel(200);
    BOOST_TEST(dog.getEnergyLevel() == 100);
    dog.setEnergyLevel(-200);
    BOOST_TEST(dog.getEnergyLevel() == 0);
}

BOOST_AUTO_TEST_CASE(GetThirst) {
    Dog dog;
    BOOST_TEST(dog.getThirst() == 100);
}

BOOST_AUTO_TEST_CASE(SetThirst) {
    Dog dog;
    dog.setThirst(50);
    BOOST_TEST(dog.getThirst() == 50);
    dog.setThirst(200);
    BOOST_TEST(dog.getThirst() == 100);
    dog.setThirst(-200);
    BOOST_TEST(dog.getThirst() == 0);
}

BOOST_AUTO_TEST_CASE(GetWeight) {
    Dog dog;
    BOOST_TEST(dog.getWeight() == 100);
}

BOOST_AUTO_TEST_CASE(SetWeight) {
    Dog dog;
    dog.setWeight(10);
    BOOST_TEST(dog.getWeight() == 10);
}

BOOST_AUTO_TEST_CASE(Update) {
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

BOOST_AUTO_TEST_CASE(PupImage) {
    BOOST_TEST(
        "   _=,_\no_/6 /#\\\n\\__ |##/\n ='|--\\\n   /   #'-.\n   \\#|_   _'-. /\n    |/ \\_( # |\" \n   C/ ,--___/"
        == Dog::pupImage());
}

BOOST_AUTO_TEST_CASE(DrinkStats) {
    Dog dog("Dog", 0, 0, 0, 0, 0, 0);
    dog.drink();
    BOOST_TEST(dog.getThirst() == 10);
    BOOST_TEST(dog.getHappiness() == 5);
    BOOST_TEST(dog.getEnergyLevel() == 5);
}

BOOST_AUTO_TEST_CASE(DrinkMessages) {
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

BOOST_AUTO_TEST_CASE(EatStats) {
    Dog dog("Dog", 0, 0, 0, 0, 0, 0);
    dog.eat();
    BOOST_TEST(dog.getHunger() == 10);
    BOOST_TEST(dog.getHappiness() == 5);
    BOOST_TEST(dog.getEnergyLevel() == 5);
    BOOST_TEST(dog.getWeight() == 5);
}

BOOST_AUTO_TEST_CASE(EatMessages) {
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

BOOST_AUTO_TEST_CASE(SleepStats) {
    Dog dog("Dog", 0, 0, 0, 0, 0, 0);
    dog.sleep();
    BOOST_TEST(dog.getEnergyLevel() == 10);
}

BOOST_AUTO_TEST_CASE(SleepMessages) {
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