#include "gtest/gtest.h"
#include "../../src/BinarySearchTree/BinarySearchTree.cpp"

/** Test Naming Requirements:
 *  - Unique Name
 *  - Name describes what it is testing
 */
namespace {
    TEST(DeleteElement, Test1_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {1, 8, 5, 7, 9, 10, 2, 3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        int elementToRemove = 3;
        EXPECT_TRUE(tree->deleteElement(elementToRemove));
        EXPECT_EQ(7, tree->getSize());
    }
    TEST(DeleteElement, Test2_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {1, 8, 5, 7, 9, 10, 2, 3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        int elementToRemove = 50;
        EXPECT_FALSE(tree->deleteElement(elementToRemove));
        EXPECT_EQ(8, tree->getSize());
    }
    TEST(DeleteElement, Test3_Int) {
        auto tree = new BinarySearchTree<int>();
        int elementToRemove = 0;
        EXPECT_FALSE(tree->deleteElement(elementToRemove));
        EXPECT_EQ(0, tree->getSize());
    }
    TEST(DeleteElement, Test1_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        std::string elementToRemove = "purple";
        EXPECT_TRUE(tree->deleteElement(elementToRemove));
        EXPECT_EQ(3, tree->getSize());
    }
    TEST(DeleteElement, Test2_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        std::string elementToRemove = "green";
        EXPECT_TRUE(tree->deleteElement(elementToRemove));
        EXPECT_EQ(3, tree->getSize());
    }
    TEST(DeleteElement, Test3_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        std::vector<std::string> expected = {};
        std::string elementToRemove = "blue";
        std::string elementToGetTree ="green";
        tree->deleteElement(elementToRemove);
        EXPECT_EQ(expected, tree->leftSubTree(elementToGetTree));
    }
}
