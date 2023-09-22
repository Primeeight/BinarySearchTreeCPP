#ifndef C343_ASSIGNMENT6_BINARYSEARCHTREE_H
#define C343_ASSIGNMENT6_BINARYSEARCHTREE_H

#include <vector>
#include "../TreeNode/TreeNode.h"

template<class T>
class BinarySearchTree {
private: // Internal Representation
    TreeNode<T> *root;
    int size = 0;

    void reclaimAllNodes(TreeNode<T> *&treeNode);//already implemented

    /** Inorder traversal from a subtree
   * @param treeNode a node to recursively find the subtree of (inorder)
   * @return a string representing the items in the tree, inorder
   **/
    std::string inorderTraversalHelper(TreeNode<T> *&treeNode);

    /** Preorder traversal from a subtree
     * @param treeNode a node to recursively find the subtree of (preorder)
     * @return a string representing the items in the tree, preorder
     **/
    std::string preorderTraversalHelper(TreeNode<T> *&treeNode);

    /** Postorder traversal from a subtree
     * @param treeNode a node to recursively find the subtree of (postorder)
     * @return a string representing the items in the tree, postorder
     **/
    std::string postorderTraversalHelper(TreeNode<T> *&treeNode);

    /** Recursive method that goes through tree to find the height from a given tree node
     * @param treeNode a given node to find the max height from
     * @return an integer representing the height
     **/
    int maxTreeHeightHelper(TreeNode<T> *&treeNode);

     /** Recursive method that goes through tree to find the total number of leaves (under the given tree node)
      * @param treeNode a given node to find the number of leaves under
      * @return an integer representing the number of leaves found
      **/
    int numberOfLeavesHelper(TreeNode<T> *&treeNode);

    /** This method converts a binary findNode tree into an inorder vector list
     *  by recursively calling the left and right subtree of each node.
     *  This list will include the root node.
    * @param current node to findNode children of (and itself)
    * @param list vector to hold all values in nodes
    **/
    void insertNodeToList(TreeNode<T> *current, std::vector<T> *list);

public:
    /** default constructor for class BinarySearchTree */
    BinarySearchTree();

    /** default deconstructor for class BinarySearchTree */
    ~BinarySearchTree();

    /** Remove all elements from the tree */
    void clear();

    /** Returns true if the element is in the tree
    * @param x value to findNode all the nodes of a given tree for
    * @return pair containing a boolean and an integer;
     *        boolean will be true if the element is found
     *        (false otherwise); the int represents number
     *        of step (comparisons) to get there, whether
     *        it is found or not
    **/
    std::pair<bool, int> contains(T &x);

    /** Insert element o into the binary tree
      * Uses an iterative algorithm
      * Duplicates should not be added to the tree
      * @param x value to be added to the binary findNode tree
      */
    void insertElement(T &x);

    /** Inorder traversal from the root*/
    std::string inorderTraversal(); //already implemented

    /** Delete an element from the binary tree.
     * Return true if the element is deleted successfully
     * Return false if the element is not in the tree
     * @param x value to be removed from the binary findNode tree
     * @return true if the element was removed; false if the element was not removed
     **/
    bool deleteElement(T &x);

    /** Preorder traversal from the root */
    std::string preorderTraversal();

    /** Postorder traversal from the root */
    std::string postorderTraversal();

    /** Returns the inorder predecessor of the specified element, returns null
     * if tree is empty or element 'e' is not in the tree.
     * @param x element to find the inorder predecessor of
     * @return Value of the inorder predecessor if there is a tree and e is in it; returns null otherwise
     **/
    T &inorderPredecessor(T &x);

    /** finds and returns the max height of the tree
    * @return integer representing the max height of the tree
    **/
    int maxTreeHeight();

    /** Returns the number of leaf nodes in this tree, returns 0 if tree is empty
     * @return integer representing the number of leaves of the tree
     **/
    int numberOfLeaves();

    /** Get the number of nodes in the tree
     *  @return integer representing the number of nodes in the tree
     **/
    int getSize();

    /** Returns an std::vector<T> containing elements in the path from the root leading
     * to the specified element, returns an empty std::vector<T> if no such element exists.
     * @param x value to findNode the tree for and find the path of
     * @return a vector containing the values making up the path to "x"
     **/
    std::vector<T> path(T &x);

    /** Returns an vector containing all elements in preorder
     * of the specified element’s left sub-tree, returns an empty vector
     * if no  such element exists.
     * @param x value to get the left sub tree of
     * @return a vector containing the values making up the left sub tree of "x"
     **/
    std::vector<T> leftSubTree(T &x);

    /** Returns an vector containing all elements in preorder
     * of the specified element’s right sub-tree, returns an empty vector if no
     * such element exists.
     * @param x value to get the right sub tree of
     * @return a vector containing the values making up the right sub tree of "x"
     **/
    std::vector<T> rightSubTree(T &x);


    TreeNode<T> *findNode(T &x);

    std::vector<T> getSubTree(TreeNode<T> current);

    void getSubTree(TreeNode<T> *current, std::vector<T> *list);
};

#endif //C343_ASSIGNMENT6_BINARYSEARCHTREE_H
