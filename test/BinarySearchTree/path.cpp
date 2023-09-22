#include "gtest/gtest.h"
#include "../../src/BinarySearchTree/BinarySearchTree.cpp"

/** Test Naming Requirements:
 *  - Unique Name
 *  - Name describes what it is testing
 */
namespace {
    TEST(Path, Test1_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[8] = {11, 3, 5, 7, 9, 10, 2, 3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        std::vector<int> expected = {11, 3, 5, 7, 9, 10};
        int pathSearch = 10;
        EXPECT_EQ(expected, tree->path(pathSearch));
    }
    TEST(Path, Test2_Int) {
        auto tree = new BinarySearchTree<int>();
        int array[1] = {3};
        for (int & i : array) {
            tree->insertElement(i);
        }
        std::vector<int> expected = {3};
        int pathSearch = 3;
        EXPECT_EQ(expected, tree->path(pathSearch));
    }
    TEST(Path, Test3_Int) {
        auto tree = new BinarySearchTree<int>();
        std::vector<int> expected = {};
        int pathSearch = 20;
        EXPECT_EQ(expected, tree->path(pathSearch));
    }
    TEST(Path, Test1_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[4] = {"green", "blue", "purple", "red"};
        for (auto & i : array) {
            tree->insertElement(i);
        }
        std::vector<std::string> expected = {"green", "purple", "red"};
        std::string pathSearch = "red";
        EXPECT_EQ(expected, tree->path(pathSearch));
    }
    TEST(Path, Test2_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[6] = {"purple", "orange", "blue", "green", "red", "yellow"};
        for (auto &i: array) {
            tree->insertElement(i);
        }
        std::vector<std::string> expected = {"purple", "orange", "blue", "green"};
        std::string pathSearch = "green";
        EXPECT_EQ(expected, tree->path(pathSearch));
    }
    TEST(Path, Test3_String) {
        auto tree = new BinarySearchTree<std::string>();
        std::string array[6] = {"purple", "blue", "orange", "green", "red", "yellow"};
        for (auto &i: array) {
            tree->insertElement(i);
        }
        std::vector<std::string> expected = {"purple", "blue", "orange", "green"};
        std::string pathSearch = "gre";
        EXPECT_EQ(expected, tree->path(pathSearch));
    }

}
