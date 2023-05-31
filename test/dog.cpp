#define BOOST_TEST_MODULE dog
#include <boost/test/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>

#include "dog.hpp"
#include "utils.hpp"

BOOST_AUTO_TEST_CASE(TestConstructor) {
    Dog dog("Nicholas", 1, 10, 1000, 1000, 1000, 100);
    BOOST_TEST(dog.getName() == std::string("Nicholas"));
    BOOST_TEST(dog.getAge() == 1);
    BOOST_TEST(dog.getWeight() == 10);
    BOOST_TEST(dog.getHunger() == 1000);
    BOOST_TEST(dog.getThirst() == 1000);
    BOOST_TEST(dog.getHappiness() == 1000);
    BOOST_TEST(dog.getEnergyLevel() == 100);
}

BOOST_AUTO_TEST_CASE(TestDefaultConstructor) {
    Dog dog;
    BOOST_TEST(dog.getName() == std::string("Dog"));
    BOOST_TEST(dog.getAge() == 72);
    BOOST_TEST(dog.getWeight() == 100);
    BOOST_TEST(dog.getHunger() == 1000);
    BOOST_TEST(dog.getThirst() == 1000);
    BOOST_TEST(dog.getHappiness() == 1000);
    BOOST_TEST(dog.getEnergyLevel() == 200);
}

BOOST_AUTO_TEST_CASE(TestGetName) {
    Dog dog;
    BOOST_TEST(dog.getName() == std::string("Dog"));
}

BOOST_AUTO_TEST_CASE(TestSetName) {
    Dog dog;
    dog.setName("Nicholas");
    BOOST_TEST(dog.getName() == std::string("Nicholas"));
}

BOOST_AUTO_TEST_CASE(TestGetAge) {
    Dog dog;
    BOOST_TEST(dog.getAge() == 72);
}

BOOST_AUTO_TEST_CASE(TestSetAge) {
    Dog dog;
    dog.setAge(1);
    BOOST_TEST(dog.getAge() == 1);
}

BOOST_AUTO_TEST_CASE(TestGetHunger) {
    Dog dog;
    BOOST_TEST(dog.getHunger() == 1000);
}

BOOST_AUTO_TEST_CASE(TestSetHunger) {
    Dog dog;
    dog.setHunger(50);
    BOOST_TEST(dog.getHunger() == 50);
    dog.setHunger(2000);
    BOOST_TEST(dog.getHunger() == 1000);
    dog.setHunger(-2000);
    BOOST_TEST(dog.getHunger() == 0);
}

BOOST_AUTO_TEST_CASE(TestGetHappiness) {
    Dog dog;
    BOOST_TEST(dog.getHappiness() == 1000);
}

BOOST_AUTO_TEST_CASE(TestSetHappiness) {
    Dog dog;
    dog.setHappiness(50);
    BOOST_TEST(dog.getHappiness() == 50);
    dog.setHappiness(2000);
    BOOST_TEST(dog.getHappiness() == 1000);
    dog.setHappiness(-2000);
    BOOST_TEST(dog.getHappiness() == 0);
}

BOOST_AUTO_TEST_CASE(TestGetEnergyLevel) {
    Dog dog;
    BOOST_TEST(dog.getEnergyLevel() == 200);
}

BOOST_AUTO_TEST_CASE(TestSetEnergyLevel) {
    Dog dog;
    dog.setEnergyLevel(50);
    BOOST_TEST(dog.getEnergyLevel() == 50);
    dog.setEnergyLevel(2000);
    BOOST_TEST(dog.getEnergyLevel() == 1000);
    dog.setEnergyLevel(-2000);
    BOOST_TEST(dog.getEnergyLevel() == 0);
}

BOOST_AUTO_TEST_CASE(TestGetThirst) {
    Dog dog;
    BOOST_TEST(dog.getThirst() == 1000);
}

BOOST_AUTO_TEST_CASE(TestSetThirst) {
    Dog dog;
    dog.setThirst(50);
    BOOST_TEST(dog.getThirst() == 50);
    dog.setThirst(2000);
    BOOST_TEST(dog.getThirst() == 1000);
    dog.setThirst(-2000);
    BOOST_TEST(dog.getThirst() == 0);
}

BOOST_AUTO_TEST_CASE(TestGetWeight) {
    Dog dog;
    BOOST_TEST(dog.getWeight() == 100);
}

BOOST_AUTO_TEST_CASE(TestSetWeight) {
    Dog dog;
    dog.setWeight(10);
    BOOST_TEST(dog.getWeight() == 10);
}

BOOST_AUTO_TEST_CASE(TestUpdate) {
    Dog dog;
    dog.startTimer();
    boost::this_thread::sleep_for(boost::chrono::milliseconds(25000));
    dog.stopTimer();
    BOOST_TEST(dog.getAge() == 73);
    BOOST_TEST(dog.getWeight() == 110);
    BOOST_TEST(dog.getHunger() == 900);
    BOOST_TEST(dog.getThirst() == 950);
    BOOST_TEST(dog.getHappiness() == 950);
    BOOST_TEST(dog.getEnergyLevel() == 150);
}

BOOST_AUTO_TEST_CASE(TestPupImage) {
    BOOST_TEST(
        "   _=,_\no_/6 /#\\\n\\__ |##/\n ='|--\\\n   /   #'-.\n   \\#|_   _'-. /\n    |/ \\_( # |\" \n   C/ ,--___/"
        == Dog::pupImage());
}

BOOST_AUTO_TEST_CASE(TestDrink) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 0, 0, 0, 0, 0);
    dog.drink();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getThirst() == 100);
    BOOST_TEST(dog.getHappiness() == 50);
    BOOST_TEST(dog.getEnergyLevel() == 50);
    BOOST_TEST(messages[1] == "Dog is drinking.");
    BOOST_TEST(messages[2] == "Dog is done drinking.");
}

BOOST_AUTO_TEST_CASE(TestEat) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 0, 0, 0, 0, 0);
    dog.eat();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHunger() == 100);
    BOOST_TEST(dog.getHappiness() == 50);
    BOOST_TEST(dog.getEnergyLevel() == 50);
    BOOST_TEST(dog.getWeight() == 5);
    BOOST_TEST(messages[1] == "Dog is eating.");
    BOOST_TEST(messages[2] == "Dog is done eating.");
}

BOOST_AUTO_TEST_CASE(TestSleep) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 0, 0, 0, 0, 0);
    dog.sleep();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getEnergyLevel() == 100);
    BOOST_TEST(messages[1] == "Dog is sleeping.");
    BOOST_TEST(messages[2] == "Dog is done sleeping.");
}
BOOST_AUTO_TEST_CASE(TestShakeHands) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.shakeHands();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 50);
    BOOST_TEST(dog.getHunger() == 50);
    BOOST_TEST(dog.getThirst() == 50);
    BOOST_TEST(messages[1] == "Dog is shaking hands.");
    BOOST_TEST(messages[2] == "Dog is done shaking hands.");
}

BOOST_AUTO_TEST_CASE(TestPlayDead) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.playDead();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 50);
    BOOST_TEST(dog.getHunger() == 50);
    BOOST_TEST(dog.getThirst() == 50);
    BOOST_TEST(messages[1] == "Dog is playing dead.");
    BOOST_TEST(messages[2] == "Dog is done playing dead.");
}

BOOST_AUTO_TEST_CASE(TestBang) {
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard(output.rdbuf());
        Dog           dog("Dog", 0, 100, 100, 100, 100, 100);
        dog.bang();
        BOOST_TEST(dog.getHappiness() == 200);
        BOOST_TEST(dog.getEnergyLevel() == 30);
        BOOST_TEST(dog.getHunger() == 50);
        BOOST_TEST(dog.getThirst() == 50);
    }
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(messages[1] == "You say the word bang to Dog.");
    BOOST_TEST(messages[2] == "Dog limps, then crawls, and then plays dead.");
    BOOST_TEST(messages[3] == "Dog stops doing the bang trick.");
}

BOOST_AUTO_TEST_CASE(TestRollOver) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.rollOver();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 0);
    BOOST_TEST(dog.getHunger() == 50);
    BOOST_TEST(dog.getThirst() == 50);
    BOOST_TEST(messages[1] == "Dog is rolling over.");
    BOOST_TEST(messages[2] == "Dog is done rolling over.");
}

BOOST_AUTO_TEST_CASE(TestBark) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.bark();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 50);
    BOOST_TEST(dog.getHunger() == 50);
    BOOST_TEST(dog.getThirst() == 50);
    BOOST_TEST(messages[1] == "Dog is barking.");
    BOOST_TEST(messages[2] == "Dog is done barking.");
}

BOOST_AUTO_TEST_CASE(TestHowl) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.howl();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 50);
    BOOST_TEST(dog.getHunger() == 50);
    BOOST_TEST(dog.getThirst() == 50);
    BOOST_TEST(messages[1] == "Dog is howling.");
    BOOST_TEST(messages[2] == "Dog is done howling.");
}

BOOST_AUTO_TEST_CASE(TestFetchBone) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.fetchBone();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 0);
    BOOST_TEST(dog.getHunger() == 0);
    BOOST_TEST(dog.getThirst() == 0);
    BOOST_TEST(messages[1] == "Dog is fetching a bone.");
    BOOST_TEST(messages[2] == "Dog is done fetching a bone.");
}

BOOST_AUTO_TEST_CASE(TestFetchStick) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.fetchStick();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 0);
    BOOST_TEST(dog.getHunger() == 0);
    BOOST_TEST(dog.getThirst() == 0);
    BOOST_TEST(messages[1] == "Dog is fetching a stick.");
    BOOST_TEST(messages[2] == "Dog is done fetching a stick.");
}

BOOST_AUTO_TEST_CASE(TestFetchBall) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.fetchBall();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 0);
    BOOST_TEST(dog.getHunger() == 0);
    BOOST_TEST(dog.getThirst() == 0);
    BOOST_TEST(messages[1] == "Dog is fetching a ball.");
    BOOST_TEST(messages[2] == "Dog is done fetching a ball.");
}

BOOST_AUTO_TEST_CASE(TestFetchFrisbee) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.fetchFrisbee();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 0);
    BOOST_TEST(dog.getHunger() == 0);
    BOOST_TEST(dog.getThirst() == 0);
    BOOST_TEST(messages[1] == "Dog is fetching a frisbee.");
    BOOST_TEST(messages[2] == "Dog is done fetching a frisbee.");
}

BOOST_AUTO_TEST_CASE(TestTugOfWar) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.tugOfWar();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST((dog.getHappiness() == 200 || dog.getHappiness() == 0));
    BOOST_TEST(dog.getEnergyLevel() == 0);
    BOOST_TEST(dog.getHunger() == 0);
    BOOST_TEST(dog.getThirst() == 0);
    BOOST_TEST(messages[1] == "You pull on one side of the rope and Dog pulls on the other side.");
    BOOST_TEST((messages[2] == "Dog won the game of tug of war." || messages[2] == "Dog lost the game of tug of war."));
}

BOOST_AUTO_TEST_CASE(TestJump) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.jump();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 0);
    BOOST_TEST(dog.getHunger() == 0);
    BOOST_TEST(dog.getThirst() == 0);
    BOOST_TEST(messages[1] == "Dog is jumping.");
    BOOST_TEST(messages[2] == "Dog is done jumping.");
}

BOOST_AUTO_TEST_CASE(TestJumpRope) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.jumpRope();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 0);
    BOOST_TEST(dog.getHunger() == 0);
    BOOST_TEST(dog.getThirst() == 0);
    BOOST_TEST(messages[1] == "Dog is jumping rope.");
    BOOST_TEST(messages[2] == "Dog is done jumping rope.");
}

BOOST_AUTO_TEST_CASE(TestJumpThroughHoop) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.jumpThroughHoop();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 0);
    BOOST_TEST(dog.getHunger() == 0);
    BOOST_TEST(dog.getThirst() == 0);
    BOOST_TEST(messages[1] == "Dog is jumping through a hoop.");
    BOOST_TEST(messages[2] == "Dog is done jumping through a hoop.");
}

BOOST_AUTO_TEST_CASE(TestJumpOverFence) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.jumpOverFence();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 0);
    BOOST_TEST(dog.getHunger() == 0);
    BOOST_TEST(dog.getThirst() == 0);
    BOOST_TEST(messages[1] == "Dog is jumping over a fence.");
    BOOST_TEST(messages[2] == "Dog is done jumping over a fence.");
}

BOOST_AUTO_TEST_CASE(TestSpin) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.spin();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 50);
    BOOST_TEST(dog.getHunger() == 50);
    BOOST_TEST(dog.getThirst() == 50);
    BOOST_TEST(messages[1] == "Dog is spinning.");
    BOOST_TEST(messages[2] == "Dog is done spinning.");
}

BOOST_AUTO_TEST_CASE(TestCrawl) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.crawl();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 200);
    BOOST_TEST(dog.getEnergyLevel() == 50);
    BOOST_TEST(dog.getHunger() == 50);
    BOOST_TEST(dog.getThirst() == 50);
    BOOST_TEST(messages[1] == "Dog is crawling.");
    BOOST_TEST(messages[2] == "Dog is done crawling.");
}

BOOST_AUTO_TEST_CASE(TestSit) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.sit();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 150);
    BOOST_TEST(dog.getEnergyLevel() == 100);
    BOOST_TEST(dog.getHunger() == 50);
    BOOST_TEST(dog.getThirst() == 50);
    BOOST_TEST(messages[1] == "Dog is sitting.");
    BOOST_TEST(messages[2] == "Dog is done sitting.");
}

BOOST_AUTO_TEST_CASE(TestLayDown) {
    boost::test_tools::output_test_stream output;
    cout_redirect                         guard(output.rdbuf());
    Dog                                   dog("Dog", 0, 100, 100, 100, 100, 100);
    dog.layDown();
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(dog.getHappiness() == 150);
    BOOST_TEST(dog.getEnergyLevel() == 150);
    BOOST_TEST(dog.getHunger() == 50);
    BOOST_TEST(dog.getThirst() == 50);
    BOOST_TEST(messages[1] == "Dog is laying down.");
    BOOST_TEST(messages[2] == "Dog is done laying down.");
}

BOOST_AUTO_TEST_CASE(TestExamineMonths) {
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard(output.rdbuf());
        Dog           dog("Dog", 0, 10, 100, 100, 100, 100);
        dog.examine();
    }
    std::vector<std::string> messages = split(output.str(), "\n");
    BOOST_TEST(messages[1] == "Dog");
    BOOST_TEST(messages[2] == "Age: 0 months");
    BOOST_TEST(messages[3] == "Weight: 10 pounds");
    BOOST_TEST(messages[4] == "Hunger: 10.0%");
    BOOST_TEST(messages[5] == "Thirst: 10.0%");
    BOOST_TEST(messages[6] == "Happiness: 10.0%");
    BOOST_TEST(messages[7] == "Energy Level: 10.0%");
}