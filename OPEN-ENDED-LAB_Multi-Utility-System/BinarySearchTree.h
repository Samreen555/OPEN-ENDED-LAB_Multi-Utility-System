#ifndef BinarySearchTree_H
#define BinarySearchTree_H

class BinarySearchTree {
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node(int v) : value(v), left(nullptr), right(nullptr) {}
    };
    Node* root;

    Node* insert(Node* node, int value);
    Node* deleteNode(Node* node, int value);
    Node* minValueNode(Node* node);
    void InOrderTraversal(Node* node);
    void PreOrderTraversal(Node* node);
    void PostOrderTraversal(Node* node);

public:
    BinarySearchTree();
    void insert(int value);
    void deleteNode(int value);
    void InOrderTraversal();
    void PreOrderTraversal();
    void PostOrderTraversal();
    ~BinarySearchTree();
};

#endif
