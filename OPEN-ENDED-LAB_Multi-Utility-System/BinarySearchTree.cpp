#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::Node* BinarySearchTree::insert(Node* node, int value) {
    if (node == nullptr) return new Node(value);
    if (value < node->value)
        node->left = insert(node->left, value);
    else
        node->right = insert(node->right, value);
	cout << "Inserted node " << node->value << endl;
    return node;
}

BinarySearchTree::Node* BinarySearchTree::deleteNode(Node* node, int value) {
    if (node == nullptr) return node;
    if (value < node->value)
        node->left = deleteNode(node->left, value);
    else if (value > node->value)
        node->right = deleteNode(node->right, value);
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = minValueNode(node->right);
        node->value = temp->value;
        node->right = deleteNode(node->right, temp->value);
    }
    cout << "Deleted node is: " << node->value << endl;
    return node;
}

BinarySearchTree::Node* BinarySearchTree::minValueNode(Node* node) {
    while (node && node->left != nullptr)
        node = node->left;
    return node;
}

void BinarySearchTree::InOrderTraversal(Node* node) {
    if (!node) return;
    InOrderTraversal(node->left);
    cout << node->value << " ";
    InOrderTraversal(node->right);
}

void BinarySearchTree::PreOrderTraversal(Node* node) {
    if (!node) return;
    cout << node->value << " ";
    PreOrderTraversal(node->left);
    PreOrderTraversal(node->right);
}

void BinarySearchTree::PostOrderTraversal(Node* node) {
    if (!node) return;
    PostOrderTraversal(node->left);
    PostOrderTraversal(node->right);
    cout << node->value << " ";
}

void BinarySearchTree::insert(int value) {
    root = insert(root, value);
}

void BinarySearchTree::deleteNode(int value) {
    root = deleteNode(root, value);
}

void BinarySearchTree::InOrderTraversal() {
    InOrderTraversal(root);
    cout << endl;
}

void BinarySearchTree:: PreOrderTraversal() {
    PreOrderTraversal (root);
    cout << endl;
}

void BinarySearchTree::PostOrderTraversal() {
    PostOrderTraversal(root);
    cout << endl;
}

BinarySearchTree::~BinarySearchTree() {
    // Properly delete all nodes in the tree
    while (root != nullptr) {
        root = deleteNode(root, root->value);
    }
}
