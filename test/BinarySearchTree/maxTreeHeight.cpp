#include "gtest/gtest.h"
#include "../../src/BinarySearchTree/BinarySearchTree.cpp"

/** Test Naming Requirements:
 *  - Unique Name
 *  - Name describes what it is testing
 */
namespace {
    TEST(MaxTreeHeight, Test1_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {1, 8, 5, 7, 9, 10, 2, 3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(5, tree->maxTreeHeight());
    }
    TEST(MaxTreeHeight, Test2_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[4] = {3, 3, 3, 3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(1, tree->maxTreeHeight());
    }
    TEST(MaxTreeHeight, Test3_Int) {
        auto tree = new BinarySearchTree<int>();
        EXPECT_EQ(0, tree->maxTreeHeight());
    }
    TEST(MaxTreeHeight, Test1_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(3, tree->maxTreeHeight());
    }
    TEST(MaxTreeHeight, Test2_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[1] = {"green"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(1, tree->maxTreeHeight());
    }
    TEST(MaxTreeHeight, Test3_String) {
        auto tree = new BinarySearchTree<std::string>();
        EXPECT_EQ(0, tree->maxTreeHeight());
    }
}
