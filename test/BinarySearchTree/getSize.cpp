#include "gtest/gtest.h"
#include "../../src/BinarySearchTree/BinarySearchTree.cpp"

/** Test Naming Requirements:
 *  - Unique Name
 *  - Name describes what it is testing
 */
namespace {
    TEST(GetSize, Test1_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {1, 8, 5, 7, 9, 10, 2, 3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(8, tree->getSize());
    }
    TEST(GetSize, Test2_Int) {
        auto tree = new BinarySearchTree<int>();
        EXPECT_EQ(0, tree->getSize());
    }
    TEST(GetSize, Test3_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {12, 3, 5, 13, 9, 10, 22, 14};
        for (int & i : array) {
            tree->insertElement(i);
        }
        auto subtree = new BinarySearchTree<int>();
        int search = 12;
        auto actual = tree->leftSubTree(search);
        for (int &j : actual) {
            subtree ->insertElement(j);
        }

        EXPECT_EQ(4, subtree->getSize());
    }
    TEST(GetSize, Test1_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(4, tree->getSize());
    }
    TEST(GetSize, Test2_String) {
        auto tree = new BinarySearchTree<std::string>();
        EXPECT_EQ(0, tree->getSize());
    }
    TEST(GetSize, Test3_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        auto subtree = new BinarySearchTree<std::string>();
        std::string search = "purple";
        auto actual = tree->leftSubTree(search);
        for (auto & j : actual) {
            subtree ->insertElement(j);
        }

        EXPECT_EQ(0, subtree->getSize());
    }
}
