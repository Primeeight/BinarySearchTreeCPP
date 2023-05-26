#include "gtest/gtest.h"
#include "../../src/BinarySearchTree/BinarySearchTree.cpp"

/** Test Naming Requirements:
 *  - Unique Name
 *  - Name describes what it is testing
 */
namespace {
    TEST(LeftSubtree, Test1_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {12, 3, 5, 13, 9, 10, 22, 14};
        for (int & i : array) {
            tree->insertElement(i);
        }
        int leftSearch = 12;
        auto actual = tree->leftSubTree(leftSearch);
        std::vector<int> expected = {3, 5, 9, 10};
        EXPECT_EQ(expected, actual);
    }
    TEST(LeftSubtree, Test1_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        std::string leftSearch = "red";
        auto actual = tree->leftSubTree(leftSearch);
        std::vector<std::string> expected = {};
        EXPECT_EQ(expected, actual);
    }
}
