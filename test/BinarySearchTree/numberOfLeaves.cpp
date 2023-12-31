#include "gtest/gtest.h"
#include "../../src/BinarySearchTree/BinarySearchTree.cpp"

/** Test Naming Requirements:
 *  - Unique Name
 *  - Name describes what it is testing
 */
namespace {
    TEST(NumberofLeaves, Test1_Int) {
    auto tree = new BinarySearchTree<int>();
    int array[8] = {1, 3, 5, 7, 9, 10, 2, 3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(2, tree->numberOfLeaves());
}
    TEST(NumberofLeaves, Test2_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[6] = {4, 3 , 6, 2, 12, 1};
        for (int & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(2, tree->numberOfLeaves());
    }
    TEST(NumberofLeaves, Test3_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[4] = {10, 5 , 2, 1};
        for (int & i : array) {
            tree->insertElement(i);
        }
        EXPECT_EQ(1, tree->numberOfLeaves());
    }
    TEST(NumberofLeaves, Test1_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[2] = {"green", "blue"};
        for (int i = 0; i < 1; i++) {
            tree->insertElement(array[i]);
        }
        EXPECT_EQ(1, tree->numberOfLeaves());
    }
    TEST(NumberofLeaves, Test2_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "red", "purple"};
        for (int i = 0; i < 1; i++) {
            tree->insertElement(array[i]);
        }
        EXPECT_EQ(1, tree->numberOfLeaves());
    }
    TEST(NumberofLeaves, Test3_String) {
        auto tree = new BinarySearchTree<std::string>();
        EXPECT_EQ(0, tree->numberOfLeaves());
    }


}
