#include "gtest/gtest.h"
#include "../../src/BinarySearchTree/BinarySearchTree.cpp"

/** Test Naming Requirements:
 *  - Unique Name
 *  - Name describes what it is testing
 */
namespace {
    TEST(PreOrderTraversal, Test1_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {8, 3, 5, 7, 9, 10, 2, 3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ("[8, 3, 2, 5, 7, 9, 10]", tree->preorderTraversal());
    }
    TEST(PreOrderTraversal, Test1_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ("[green, blue, purple, red]", tree->preorderTraversal());

    }
}
