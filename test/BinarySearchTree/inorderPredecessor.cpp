#include "gtest/gtest.h"
#include "../../src/BinarySearchTree/BinarySearchTree.cpp"

/** Test Naming Requirements:
 *  - Unique Name
 *  - Name describes what it is testing
 */
namespace {
    TEST(InorderPredecessor, Test1_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {1, 3, 53, 76, 9, 10, 2, 3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        int searchNum = 3;
        EXPECT_EQ(2, tree->inorderPredecessor(searchNum));
    }
    //Seg fault
    TEST(InorderPredecessor, Test2_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[1] = {1};
        for (int & i : array) {
            tree->insertElement(i);
        }
        int searchNum = 3;
        EXPECT_EQ(searchNum, tree->inorderPredecessor(searchNum));
    }
    TEST(InorderPredecessor, Test3_Int) {
        auto tree = new BinarySearchTree<int>();
        int searchNum = 5;
        EXPECT_EQ(searchNum, tree->inorderPredecessor(searchNum));
    }
    TEST(InorderPredecessor, Test1_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        std::string searchWord = "red";
        std::string result = "purple";
        EXPECT_EQ(result, tree->inorderPredecessor(searchWord));
    }
    TEST(InorderPredecessor, Test2_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        std::string searchWord = "red";
        std::string result = "purple";
        EXPECT_EQ(result, tree->inorderPredecessor(searchWord));
    }
    TEST(InorderPredecessor, Test3_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        std::string searchWord = "red";
        std::string result = "purple";
        EXPECT_EQ(result, tree->inorderPredecessor(searchWord));
    }
}
