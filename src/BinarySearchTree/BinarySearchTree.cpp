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
    if (root == NULL) {
        root = new TreeNode<T>;
        root->value = x;
    } else {
        TreeNode<T> current = findNode(x);
        if (current.value == x) {
            return;
        }
        if (current.parent.value < x) {
            current.parent.left = new TreeNode<T>;
            current.parent.left->value = x;
        } else {
            current.parent.right = new TreeNode<T>;
            current.parent.right->value = x;
        }
        size++;
    }

}//insert

template<class T>
bool BinarySearchTree<T>::deleteElement(T &x) {
    // TODO Search tree for element x and delete it if found; return true if deleted, false if not found
    TreeNode<T> current = findNode(x);
    //if current is not in the tree.
    if (current != x)
        return false;
    //Case 1: current has no left child.
    if (current.left == NULL) {
        if (current.parent == NULL) {
            root = current.right;
        } else {
            if (current.parent->value == x)
                current.parent->left = current.right;
            else
                current.parent->right = current.right;
        }
//Case 2: The current node has a left child
    } else {
        TreeNode<T> parentOfRightMost = current;
        TreeNode<T> rightMost = current.left;

        while (rightMost.right != NULL) {
            parentOfRightMost = rightMost;
            rightMost = rightMost.right;
        }

        // Replace the element in current by the element in rightMost
        current.value = rightMost.value;

        // Eliminate rightmost node
        if (parentOfRightMost.right == rightMost)
            parentOfRightMost.right = rightMost.left;
        else
            // Special case: parentOfRightMost == current
            parentOfRightMost.left = rightMost.left;
    }

    size--; // Reduce the size of the tree
    return true; // Element deleted successfully

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
    //Base case
    if (treeNode->left == NULL && treeNode->right == NULL)
        return ss.str();
    else {
        //recursive case
        return inorderTraversalHelper(treeNode->left) + treeNode->value + inorderTraversalHelper(treeNode->right);
    }
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
    //Base case
    if (treeNode->left == NULL && treeNode->right == NULL)
        return ss.str();
    else {
        //recursive case
        return treeNode->value + inorderTraversalHelper(treeNode->left) + inorderTraversalHelper(treeNode->right);
    }
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
    //Base case
    if (treeNode->left == NULL && treeNode->right == NULL)
        return ss.str();
    else {
        //recursive case
        return inorderTraversalHelper(treeNode->left) + inorderTraversalHelper(treeNode->right) + treeNode->value;
    }
}


//private
template<class T>
T &BinarySearchTree<T>::inorderPredecessor(T &x) {
    TreeNode<T> *current = root;
    // TODO locates the inorderPredecessor of element x, if x is in the tree
    current = findNode(x);
    return current->parent->value;
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
    if (treeNode->value != NULL) {
        if (treeNode->left == NULL && treeNode->right == NULL)
            return 0;
        else {
            //recursive case
            return 1 + max(maxTreeHeightHelper(treeNode->left), maxTreeHeightHelper(treeNode->right));
        }
    }
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
    if (treeNode->value != NULL) {
        if (treeNode->left == NULL && treeNode->right == NULL)
            return 1;
        else {
            //recursive case
            return numberOfLeavesHelper(treeNode->left) + numberOfLeavesHelper(treeNode->right);
        }
    }
    return 0;
}

template<class T>
int BinarySearchTree<T>::getSize() { // THIS IS COMPLETE
    return size;
}

template<class T>
std::pair<bool, int> BinarySearchTree<T>::contains(T &x) {
    // TODO Searches through the tree to find element x and returns std::pair<bool, int>(true, counter); if it is found
    std::vector<T> newPath = path(x);
    int counter = newPath.size();

    if (newPath.back() == x) {
        return std::pair(true, counter);
    }

    return std::pair<bool, int>(false, counter);
}

template<class T>
std::vector<T> BinarySearchTree<T>::path(T &x) {
    auto list = new std::vector<T>();
    if (root == NULL) {
        return *list;
    }
    TreeNode<T> current = root;
    current.parent = NULL;
    while (current.value != NULL) {
        if (current.value < x) {
            list->push_back(current.value);
            current.parent = current;
            current = current.left;
        } else if (current.value > x) {
            list->push_back(current.value);
            current.parent = current;
            current = current.right;
        } else {
            list->push_back(current.value);
            return *list;
        }
    }

    // TODO creates the path to the given element x in the vector object

}

template<class T>
std::vector<T> BinarySearchTree<T>::leftSubTree(T &x) {
    TreeNode<T> *current = findNode(x);
    // TODO creates a vector containing the items in the left subtree of element x in preorder

    return getSubTree(current->left);
}

template<class T>
std::vector<T> BinarySearchTree<T>::getSubTree(TreeNode<T> current) {
    auto list = new std::vector<T>();
    list->push_back(current.value);
    list->push_back(current.left);
    list->push_back(current.right);

}

template<class T>
std::vector<T> BinarySearchTree<T>::rightSubTree(T &x) {
    TreeNode<T> *current = findNode(x);
    // TODO creates a vector containing the items in the right subtree of element x in preorder
    return getSubTree(current->right);
}

/**
 * TODO ensure that correct node is being returned.
 * Provides the iterative algorithm for finding an element and its node within the tree.
 * Returns the tree node if found, otherwise returns the closest node.
 * @tparam T
 * @param x
 * @return
 */
template<class T>
TreeNode<T> BinarySearchTree<T>::findNode(T &x) {
    TreeNode<T> current = root;
    current.parent = NULL;
    while (current.value != NULL) {
        if (current.value < x) {
            current.parent = current;
            current = current.left;
        } else if (current.value > x) {
            current.parent = current;
            current = current.right;
        } else
            return current;
    }
    return current;
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

