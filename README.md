# C++ Binary Search Tree

<img src="https://docs.csgrader.org/files/readme/BST.svg" height="auto" width="auto" style="border-radius:3%">

## Description
Complete the Binary Search Tree class in the /src directory. The TreeNode class is given.
**You must use pointers for this assignment.**

## IMPORTANT
To access a child nodes pointers you would use:
```this->left->right->value```

### Boundary Conditions To Consider

1. What happens in the methods if the position is out of bounds?

2. What is the length of an empty binary search tree?

3. What is the outcome of contains function if the position is out of bounds?

4. What is the outcome of delete function if the position is out of bounds?

5. What is the outcome of clear function if binary search tree is already empty?

## Required Tasks
To complete this assignment you must do the following:

- Complete the BinarySearchTree.cpp file; use TODOS as reference of where to start
- Ensure all tests pass.
- Have at least **6 total** unit tests in each test file. 3 for integers; 3 for strings.
- [Have your code coverage be a minimum of 80%](https://www.jetbrains.com/help/idea/running-test-with-coverage.html#run-config-with-coverage).



## Resources
- [Samples](https://github.com/google/googletest/tree/main/googletest/samples)
- [Cmake tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
- [Google Test docs](https://google.github.io/googletest/quickstart-cmake.html)
- [Tutorial on stringstream](https://www.softwaretestinghelp.com/stringstream-class-in-cpp/)
