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
    if (root == NULL) {
        root = new TreeNode<T>;
        root->value = x;
        root->right = NULL;
        root->left = NULL;
        size++;
    } else {

        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;
        while (current != NULL) {
            if (current->value > x) {
                parent = current;
                current = current->left;
            } else if (current->value < x) {
                parent = current;
                current = current->right;
            } else
                return;
        }

        if (parent->value > x) {
            parent->left = new TreeNode<T>;
            parent->left->value = x;
            parent->left->left = NULL;
            parent->left->right = NULL;
        } else {
            parent->right = new TreeNode<T>;
            parent->right->value = x;
            parent->right->left = NULL;
            parent->right->right = NULL;
        }
        size++;
    }

}//insert

template<class T>
bool BinarySearchTree<T>::deleteElement(T &x) {
    //if current is not in the tree or root is NULL.
    if (root == NULL)
        return false;
    if (contains(x).first == false)
        return false;
    //Case 1: current has no left child.
    TreeNode<T> *current = findNode(x);
    if (current->left == NULL) {


        if (current->parent == NULL) {
            root = current->right;
        }



        else {
            if (current->parent->value > x)
                current->parent->left = current->right;
            else
                current->parent->right = current->right;
        }
//Case 2: The current node has a left child
    } else {
        TreeNode<T> *parentOfRightMost = current;
        TreeNode<T> *rightMost = current->left;

        while (rightMost->right != NULL) {
            parentOfRightMost = rightMost;
            rightMost = rightMost->right;
        }

        // Replace the element in current by the element in rightMost
        current->value = rightMost->value;

        // Eliminate rightmost node
        if (parentOfRightMost->right == rightMost)
            parentOfRightMost->right = rightMost->left;
        else
            // Special case: parentOfRightMost == current
            parentOfRightMost->left = rightMost->left;
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
    std::string result;

    //Base case
    if (treeNode == NULL) {
        return ss.str();
    } else {
        //recursive case
        ss << inorderTraversalHelper(treeNode->left) << treeNode->value << ", "
           << inorderTraversalHelper(treeNode->right);
        //String formatting here.
        if (treeNode == root) {
            result = ss.str();
            result = result.substr(0, result.length() - 2);
            ss.str("");
            ss << result;

        }
        return ss.str();
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
    std::string result;

    //ss << "string";
    // TODO recursively builds a string preorder (adds current element, calls left subtree, calls rights subtree)
    //Base case
    if (treeNode == NULL)
        return ss.str();
    else {
        //recursive case
        ss << ", " << treeNode->value << preorderTraversalHelper(treeNode->left)
           << preorderTraversalHelper(treeNode->right);
        if (treeNode == root) {
            result = ss.str();
            result = result.substr(2, result.length() - 2);
            ss.str("");
            ss << result;

        }
        return ss.str();
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
    std::string result;
    // TODO recursively builds a string postorder (calls left subtree, calls rights subtree, adds current element)
    //Base case
    if (treeNode == NULL)
        return ss.str();
    else {
        //recursive case
        ss << postorderTraversalHelper(treeNode->left) << postorderTraversalHelper(treeNode->right) << treeNode->value
           << ", ";
        //String formatting here.
        if (treeNode == root) {
            result = ss.str();
            result = result.substr(0, result.length() - 2);
            ss.str("");
            ss << result;

        }
        return ss.str();
    }
}


//private
template<class T>
T &BinarySearchTree<T>::inorderPredecessor(T &x) {
    /**locates the inorderPredecessor of element x, if x is in the tree
     * If x is not in the tree or the tree is empty, returns NULL.
     * If x is the only element in the tree, returns x.
     *
     */


    TreeNode<T> *current = NULL;
    if (contains(x).first == false || maxTreeHeight() == 0) {
        return x;

    }
    current = findNode(x);
    if (current->left != NULL) {
        return current->left->value;
    } else if (current->parent != NULL) {
        return current->parent->value;
    }
    return current->value;


}

//public
template<class T>
int BinarySearchTree<T>::maxTreeHeight() { // THIS IS COMPLETE
    return maxTreeHeightHelper(root);
}

//private
template<class T>
int BinarySearchTree<T>::maxTreeHeightHelper(TreeNode<T> *&treeNode) {

    if (treeNode == NULL) {
        return 0;
    } else {
        //recursive case
        return std::max(1 + maxTreeHeightHelper(treeNode->left), 1 + maxTreeHeightHelper(treeNode->right));
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
    if (treeNode != NULL) {
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

    std::vector<T> newPath = path(x);
    int counter = newPath.size();
    if (root != NULL) {
        if (newPath.back() == x) {
            return std::pair(true, counter);
        }

    }
    return std::pair<bool, int>(false, counter);
}

template<class T>
std::vector<T> BinarySearchTree<T>::path(T &x) {
    auto list = new std::vector<T>();
    if (root == NULL) {
        return *list;
    }
    TreeNode<T> *current = root;
    current->parent = NULL;
    while (current != NULL) {
        if (current->value > x) {
            list->push_back(current->value);
            current->parent = current;
            current = current->left;
        } else if (current->value < x) {
            list->push_back(current->value);
            current->parent = current;
            current = current->right;
        } else {
            list->push_back(current->value);
            return *list;
        }
    }
    return *list;
}

template<class T>
std::vector<T> BinarySearchTree<T>::leftSubTree(T &x) {
    auto list = new std::vector<T>();
    if (contains(x).first) {
        //use findNode to get to the current element.
        TreeNode<T> *current = findNode(x);
        getSubTree(current->left, list);
    }

    return *list;
}

template<class T>
void BinarySearchTree<T>::getSubTree(TreeNode<T> *current, std::vector<T> *list) {

    //this is returning a pointer to a vector.

    if (current != NULL) {
        T value = current->value;
        (*list).emplace_back(value);
        getSubTree(current->left, list);
        getSubTree(current->right, list);
    }
}

template<class T>
std::vector<T> BinarySearchTree<T>::rightSubTree(T &x) {

    auto list = new std::vector<T>();
    if (contains(x).first) {
        TreeNode<T> *current = findNode(x);
        getSubTree(current->right, list);
    }
    return *list;
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
TreeNode<T> *BinarySearchTree<T>::findNode(T &x) {
    TreeNode<T> *current = root;
    current->parent = NULL;
    if (contains(x).first) {
        while (current != NULL) {
            //Seg fault
            if (current->value > x) {
                current->left->parent = current;
                current = current->left;
            } else if (current->value < x) {
                current->right->parent = current;
                current = current->right;
            } else
                return current;
        }
    }
    return current->parent;
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

