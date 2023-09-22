#include "gtest/gtest.h"
#include "../../src/BinarySearchTree/BinarySearchTree.cpp"

/** Test Naming Requirements:
 *  - Unique Name
 *  - Name describes what it is testing
 */
namespace {
    TEST(InOrderTraversal, Test01_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[13] = {1, 3, 5, 7, 9, 10, 2, 3, -8, -10, 0, -9, 6};
        for (int & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ("[-10, -9, -8, 0, 1, 2, 3, 5, 6, 7, 9, 10]",tree->inorderTraversal());
    }
    TEST(InOrderTraversal, Test02_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[10] = {10, 9, 8, 7, 6, 5, 4, 3 ,2 ,1};
        for (int & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ("[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]",tree->inorderTraversal());
    }
    TEST(InOrderTraversal, Test03_Int) {
        auto tree = new BinarySearchTree<int>();
        EXPECT_EQ("[]",tree->inorderTraversal());
    }

    TEST(InOrderTraversal, Test01_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[7] = {"M", "A", "F", "B", "E", "C", "D"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ("[A, B, C, D, E, F, M]", tree->inorderTraversal());
    }
    TEST(InOrderTraversal, Test02_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[7] = {};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ("[]", tree->inorderTraversal());
    }
    TEST(InOrderTraversal, Test03_String) {
        auto tree = new BinarySearchTree<std::string>();
        EXPECT_EQ("[]",tree->inorderTraversal());
    }
}
