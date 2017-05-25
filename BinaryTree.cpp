#include"BinaryTree.h"

template <class T> void BinaryTree<T>::floorOrderTraversal() {
	queue<Node<T>> q;
	q.push(root);
	while (!q.empty()) {
		Node<T> n = q.front();
		cout << n.value << '\t';
		q.pop();
		if (n.left != NULL) {
			q.push(n.left);
		}
		if (n.right != NULL) {
			q.push(n.right);
		}
	}
}

template <class T> void BinaryTree<T>::inOrderTraversalNonRecursive() {
	stack<Node<T>> s;
	Node<T> n = head;
	while (n != NULL) {
		s.push(n);
		n=n.left;
	}
	while (!s.empty()) {
		n = s.top();
		s.pop();
		cout << n.value << '\t';
		if (n.right != NULL) {
			n = n.right;
			while (n != NULL) {
				s.push(n);
				n = n.left;
			}
		}
	}
}
template <class T> void BinaryTree<T>::preOrderTraversalNonRecursive() {
	stack<Node<T>> s;
	if (root != NULL) {
		s.push(root);
	}
	while (!s.empty()) {
		Node<T> n = s.top();
		s.pop();
		cout << n.value << '\t';
		if (n.right != NULL) {
			s.push(n.right);
		}
		if (n.left != NULL) {
			s.push(n.left);
		}
	}
}
template <class T> void BinaryTree<T>::posOrderTraversalNonRecursive() {
	stack<Node<T>> s;
	Node<T> n = head;
	while (n != NULL) {
		s.push(n);
		n = n.left;
	}
	Node<T> pre = NULL;
	while (!s.empty()) {
		n = s.top();
		if (n.right != NULL&&n.right != pre) {
			n = n.right;
			while (n != NULL) {
				s.push(n);
				n = n.left;
			}
		}else{
			cout << n.value << '\t';
			s.pop();
			pre = n;
		}
	}
}

template <class T> void BinaryTree<T>::inOrderTraversalRecursive() {
	inOrderTraversalRecursiveNode(root);
}
template <class T> void BinaryTree<T>::preOrderTraversalRecursive() {
	preOrderTraversalRecursiveNode(root);
}
template <class T> void BinaryTree<T>::posOrderTraversalRecursive() {
	posOrderTraversalRecursiveNode(root);
}




template <class T> void BinaryTree<T>::inOrderTraversalRecursiveNode(Node<T> n) {
	if (n != NULL) {
		inOrderTraversalRecursiveNode(n.left);
		cout << n.value << '\t';
		inOrderTraversalRecursiveNode(n.right);
	}
}
template <class T> void BinaryTree<T>::preOrderTraversalRecursiveNode(Node<T> n) {
	if (n != NULL) {
		cout << n.value << '\t';
		preOrderTraversalRecursiveNode(n.left);
		preOrderTraversalRecursiveNode(n.right);
	}
}
template <class T> void BinaryTree<T>::posOrderTraversalRecursiveNode(Node<T> n) {
	if (n != NULL) {
		posOrderTraversalRecursiveNode(n.left);
		posOrderTraversalRecursiveNode(n.right);
		cout << n.value << '\t';
	}
}