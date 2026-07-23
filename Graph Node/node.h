#ifndef NODE
#define NODE

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Node{
    T val;
    Node<T> *parent;
    vector<Node<T> *> neighbours;

    Node() : val(), parent(nullptr), neighbours({}) {}
    Node(T x) : val(x), parent(nullptr), neighbours({}) {}
    Node(T x, Node<T> *p) : val(x), parent(p), neighbours({}) {}
    Node(T x, Node<T> *p, vector<Node<T> *>& c) : val(x), parent(p), neighbours(c) {}

};

template <typename T>
struct TreeNode{
    T val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(), left(nullptr), right(nullptr) {}
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(T x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

#endif