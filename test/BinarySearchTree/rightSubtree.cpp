#include "gtest/gtest.h"
#include "../../src/BinarySearchTree/BinarySearchTree.cpp"

/** Test Naming Requirements:
 *  - Unique Name
 *  - Name describes what it is testing
 */
namespace {
    TEST(RightSubtree, Test1_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {12, 3, 5, 13, 9, 10, 22, 14};
       for (int & i : array) {
           tree->insertElement(i);
        }
       int rightSearch = 12;
        auto actual = tree->rightSubTree(rightSearch);
       std::vector<int> expected = {13, 22, 14};
       EXPECT_EQ(expected, actual);
    }
    TEST(RightSubtree, Test1_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        std::string rightSearch = "red";
        auto actual = tree->rightSubTree(rightSearch);
        std::vector<std::string> expected = {};
        EXPECT_EQ(expected, actual);
    }
}
