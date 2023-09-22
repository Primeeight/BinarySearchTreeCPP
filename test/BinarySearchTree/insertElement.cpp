#include "gtest/gtest.h"
#include "../../src/BinarySearchTree/BinarySearchTree.cpp"

/** Test Naming Requirements:
 *  - Unique Name
 *  - Name describes what it is testing
 */
namespace {
    TEST(InsertElement, Test1_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {1, 3, 5, 7, 9, 10, 2, 3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(7, tree->getSize());
    }
    TEST(InsertElement, Test2_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {5, 4, 3, 2, 1 ,1*2, 2*2, 3*3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(6, tree->getSize());
    }
    TEST(InsertElement, Test3_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {1, 3, 5, 7, 9, 10, 2, 3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(7, tree->getSize());
    }
    TEST(InsertElement, Test1_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"sun", "sun", "sun", "three body problem?"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(2, tree->getSize());
    }
    TEST(InsertElement, Test2_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(4, tree->getSize());
    }
    TEST(InsertElement, Test3_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"z", "yx", "wxv", "qrus"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(4, tree->getSize());
    }
}
