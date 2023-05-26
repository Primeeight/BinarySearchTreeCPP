#ifndef C343_ASSIGNMENT6_TREENODE_H
#define C343_ASSIGNMENT6_TREENODE_H

template <class T>
class TreeNode {
public:
    T value;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode<T>* parent;

      TreeNode() = default;

};


#endif //C343_ASSIGNMENT6_TREENODE_H
