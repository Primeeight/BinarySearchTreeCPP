#include "gtest/gtest.h"
#include "../../src/BinarySearchTree/BinarySearchTree.cpp"

/** Test Naming Requirements:
 *  - Unique Name
 *  - Name describes what it is testing
 */
namespace {
    TEST(Contains, Test1_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {1, 8, 5, 7, 9, 10, 2, 3};
        for (int &i: array) {
            tree->insertElement(i);
        }
        int containsValue = 3;
        std::pair<bool, int> actual = tree->contains(containsValue);
        EXPECT_TRUE(actual.first);
        EXPECT_EQ(5, actual.second);
    }

    TEST(Contains, Test2_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {1, 8, 5, 7, 9, 10, 2, 3};
        for (int &i: array) {
            tree->insertElement(i);
        }
        int containsValue = 1;
        std::pair<bool, int> actual = tree->contains(containsValue);
        EXPECT_TRUE(actual.first);
        EXPECT_EQ(1, actual.second);
    }

    TEST(Contains, Test3_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {1, 8, 5, 7, 9, 10, 2, 3};
        for (int &i: array) {
            tree->insertElement(i);
        }
        int containsValue = 3;
        tree->deleteElement(containsValue);
        std::pair<bool, int> actual = tree->contains(containsValue);
        EXPECT_FALSE(actual.first);
        EXPECT_EQ(4, actual.second);
    }

    TEST(Contains, Test1_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto &i: array) {
            tree->insertElement(i);
        }
        std::string containsValue = "peach";
        std::pair<bool, int> actual = tree->contains(containsValue);
        EXPECT_FALSE(actual.first);
        EXPECT_EQ(2, actual.second);
    }

    TEST(Contains, Test2_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto &i: array) {
            tree->insertElement(i);
        }
        std::string containsValue = "red";
        std::pair<bool, int> actual = tree->contains(containsValue);
        EXPECT_TRUE(actual.first);
        EXPECT_EQ(3, actual.second);
    }

    TEST(Contains, Test3_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string containsValue = "red";
        std::pair<bool, int> actual = tree->contains(containsValue);
        EXPECT_FALSE(actual.first);
        EXPECT_EQ(0, actual.second);
    }
}
