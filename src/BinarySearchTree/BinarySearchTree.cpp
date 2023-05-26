#include <iostream>
#include "BinarySearchTree.h"
#include <algorithm>
#include <string>
#include <sstream>

template<class T>
BinarySearchTree<T>::BinarySearchTree() { // THIS IS COMPLETE
    root = NULL;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree() { // THIS IS COMPLETE
    reclaimAllNodes(root);
}

template<class T>
void BinarySearchTree<T>::clear() { // THIS IS COMPLETE
    reclaimAllNodes(root);
    root = NULL;
    size = 0;
} // clear

template<class T>
void BinarySearchTree<T>::reclaimAllNodes(TreeNode<T> *&treeNode) { // THIS IS COMPLETE
    if (treeNode != NULL) {
        reclaimAllNodes(treeNode->left);
        reclaimAllNodes(treeNode->right);
        treeNode->parent = NULL;
        treeNode->left = NULL;
        treeNode->right = NULL;
        delete (treeNode);
    } // end if
} // reclaimAllNodes

template<class T>
void BinarySearchTree<T>::insertElement(T &x) {
    // TODO Insert given x element into the tree at proper location, if it isn't already in the tree

}//insert


template<class T>
bool BinarySearchTree<T>::deleteElement(T &x) {
    // TODO Search tree for element x and delete it if found; return true if deleted, false if not found
}//delete

template<class T>
std::string BinarySearchTree<T>::inorderTraversal() { // THIS IS COMPLETE
    return "[" + inorderTraversalHelper(root) + "]";
}

template<class T>
std::string BinarySearchTree<T>::inorderTraversalHelper(TreeNode<T> *&treeNode) {
    std::stringstream ss;
    ss << "string";
    // TODO recursively builds a string inorder (calls left subtree, adds current element, calls rights subtree)
    return ss.str();
}

//public
template<class T>
std::string BinarySearchTree<T>::preorderTraversal() { // THIS IS COMPLETE
    return "[" + preorderTraversalHelper(root) + "]";
}

//private
template<class T>
std::string BinarySearchTree<T>::preorderTraversalHelper(TreeNode<T> *&treeNode) {
    std::stringstream ss;
    ss << "string";
    // TODO recursively builds a string preorder (adds current element, calls left subtree, calls rights subtree)
    return ss.str();
}

//public
template<class T>
std::string BinarySearchTree<T>::postorderTraversal() { // THIS IS COMPLETE
    return "[" + postorderTraversalHelper(root) + "]";
}

//private
template<class T>
std::string BinarySearchTree<T>::postorderTraversalHelper(TreeNode<T> *&treeNode) {
    std::stringstream ss;
    ss << "string";
    // TODO recursively builds a string postorder (calls left subtree, calls rights subtree, adds current element)
    return ss.str();
}


//private
template<class T>
T &BinarySearchTree<T>::inorderPredecessor(T &x) {
    TreeNode<T> *current = root;
    TreeNode<T> *previous = current;
    // TODO locates the inorderPredecessor of element x, if x is in the tree
    return previous->value;
}

//public
template<class T>
int BinarySearchTree<T>::maxTreeHeight() { // THIS IS COMPLETE
    return maxTreeHeightHelper(root);
}

//private
template<class T>
int BinarySearchTree<T>::maxTreeHeightHelper(TreeNode<T> *&treeNode) {
    // TODO Recursively determines the height of given treeNode
    return 0;
}

//public
template<class T>
int BinarySearchTree<T>::numberOfLeaves() { // THIS IS COMPLETE
    if (root == NULL) {
        return 0;
    }
    return numberOfLeavesHelper(root);
}

//private
template<class T>
int BinarySearchTree<T>::numberOfLeavesHelper(TreeNode<T> *&treeNode) {
    // TODO Recursively determines the number of leaves under given treeNode
    return 0;
}

template<class T>
int BinarySearchTree<T>::getSize() { // THIS IS COMPLETE
    return size;
}

template<class T>
std::pair<bool, int> BinarySearchTree<T>::contains(T &x) {
    TreeNode<T> *current = root;
    int counter = 0;

    // TODO Searches through the tree to find element x and returns std::pair<bool, int>(true, counter); if it is found

    return std::pair<bool, int>(false, counter);
}

template<class T>
std::vector<T> BinarySearchTree<T>::path(T &x) {
    auto list = new std::vector<T>();
    if (root == NULL) {
        return *list;
    }

    // TODO creates the path to the given element x in the vector object

    return *list;
}

template<class T>
std::vector<T> BinarySearchTree<T>::leftSubTree(T &x) {
    auto list = new std::vector<T>();
    TreeNode<T> *current = root;

    // TODO creates a vector containing the items in the left subtree of element x in preorder

    return *list;
}

template<class T>
std::vector<T> BinarySearchTree<T>::rightSubTree(T &x) {
    auto list = new std::vector<T>();
    TreeNode<T> *current = root;

    // TODO creates a vector containing the items in the right subtree of element x in preorder

    return *list;
}

template<class T>
void BinarySearchTree<T>::insertNodeToList(TreeNode<T> *current, std::vector<T> *list) { // THIS IS COMPLETE
    if (current != NULL) {
        T value = current->value;
        insertNodeToList(current->left, list);
        (*list).emplace_back(value);
        insertNodeToList(current->right, list);
    }
}

