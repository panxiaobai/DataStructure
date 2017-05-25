#pragma once
#include <queue>
#include <stack>
#include<iostream>
using namespace std;

template <class T>
struct Node {
	T value;
	Node *left;
	Node *right;
};

template <class T>
class BinaryTree {
private:
	Node<T> root;
public:
	void floorOrderTraversal();
	void inOrderTraversalNonRecursive();
	void preOrderTraversalNonRecursive();
	void posOrderTraversalNonRecursive();
	void inOrderTraversalRecursive();
	void preOrderTraversalRecursive();
	void posOrderTraversalRecursive();
	void inOrderTraversalRecursiveNode(Node<T> n);
	void preOrderTraversalRecursiveNode(Node<T> n);
	void posOrderTraversalRecursiveNode(Node<T> n);
};