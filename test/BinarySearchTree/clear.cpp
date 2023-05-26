#include "gtest/gtest.h"
#include "../../src/BinarySearchTree/BinarySearchTree.cpp"

/** Test Naming Requirements:
 *  - Unique Name
 *  - Name describes what it is testing
 */

namespace {
    TEST(Clear, Test1_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {1, 8, 5, 7, 9, 10, 2, 3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        tree->clear();
        EXPECT_EQ(0, tree->getSize());
    }
    TEST(Clear, Test1_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (int i = 0; i < 4; i++) {
            tree->insertElement(array[i]);
        }
       tree->clear();
        EXPECT_EQ(0, tree->getSize());
    }
}
