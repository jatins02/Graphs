#ifndef NODE
#define NODE

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Node{
    T val;
    Node<T> *parent;
    vector<Node<T> *> children;

    Node() : val(), parent(nullptr), children({}) {}
    Node(T x) : val(x), parent(nullptr), children({}) {}
    Node(T x, Node<T> *p) : val(x), parent(p), children({}) {}
    Node(T x, Node<T> *p, const vector<Node<T> *>& c) : val(x), parent(p), children(c) {}

    // some useful getter methods
    T getVal(){
        return val;
    }
    Node<T> *getParent(){
        return parent;
    }
};

#endif