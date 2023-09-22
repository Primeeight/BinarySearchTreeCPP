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
    TEST(LeftSubtree, Test2_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {12, 3, 5, 13, 9, 10, 22, 14};
        for (int & i : array) {
            tree->insertElement(i);
        }
        int leftSearch = 14;
        auto actual = tree->leftSubTree(leftSearch);
        std::vector<int> expected = {};
        EXPECT_EQ(expected, actual);

    }
    TEST(LeftSubtree, Test3_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[7] = {12, 12, 6, 4, 3, 2, 1};
        for (int & i : array) {
            tree->insertElement(i);
        }
        int leftSearch = 12;
        auto actual = tree->leftSubTree(leftSearch);
        std::vector<int> expected = {6, 4, 3, 2, 1};
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
    TEST(LeftSubtree, Test2_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[6] = {"purple", "orange", "blue", "green", "red", "yellow"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        std::string leftSearch = "purple";
        auto actual = tree->leftSubTree(leftSearch);
        std::vector<std::string> expected = {"orange", "blue", "green"};
        EXPECT_EQ(expected, actual);
    }
    TEST(LeftSubtree, Test3_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[1] = {"purple"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        std::string leftSearch = "green";
        auto actual = tree->leftSubTree(leftSearch);
        std::vector<std::string> expected = {};
        EXPECT_EQ(expected, actual);
    }
}
