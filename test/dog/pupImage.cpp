#define BOOST_TEST_MODULE dog_pup_image
#include <boost/test/unit_test.hpp>

#include "dog.hpp"

BOOST_AUTO_TEST_CASE(pupImage) {
    BOOST_TEST(
        "   _=,_\no_/6 /#\\\n\\__ |##/\n ='|--\\\n   /   #'-.\n   \\#|_   _'-. /\n    |/ \\_( # |\" \n   C/ ,--___/"
        == Dog::pupImage());
}