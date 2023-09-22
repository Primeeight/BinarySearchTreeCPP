#include "gtest/gtest.h"
#include "../../src/BinarySearchTree/BinarySearchTree.cpp"

/** Test Naming Requirements:
 *  - Unique Name
 *  - Name describes what it is testing
 */
namespace {
    TEST(PostOrderTraversal, Test1_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {1, 3, 5, 7, 9, 10, 2, 3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ("[2, 10, 9, 7, 5, 3, 1]",tree->postorderTraversal());
    }
    TEST(PostOrderTraversal, Test02_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[10] = {10, 9, 8, 7, 6, 5, 4, 3 ,2 ,1};
        for (int & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ("[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]",tree->postorderTraversal());
    }
    TEST(PostOrderTraversal, Test03_Int) {
        auto tree = new BinarySearchTree<int>();
        EXPECT_EQ("[]",tree->postorderTraversal());
    }
    TEST(PostOrderTraversal, Test1_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ("[blue, red, purple, green]", tree->postorderTraversal());

    }
    TEST(PostOrderTraversal, Test02_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[7] = {};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ("[]", tree->postorderTraversal());
    }
    TEST(PostOrderTraversal, Test03_String) {
        auto tree = new BinarySearchTree<std::string>();
        EXPECT_EQ("[]",tree->postorderTraversal());
    }
}
