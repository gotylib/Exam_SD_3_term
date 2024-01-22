#pragma once
#include <iostream>

using namespace std;

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        height = 1;
        left = right = nullptr;
    }
};

class AVLTree {
private:
    Node* root;
    struct Trunk
    {
        Trunk* prev;
        string str;

        Trunk(Trunk* prev, string str)
        {
            this->prev = prev;
            this->str = str;
        }
    };

    // Вспомогательная функция для печати ветвей бинарного дерева
    void showTrunks(Trunk* p)
    {
        if (p == nullptr) {
            return;
        }

        showTrunks(p->prev);
        cout << p->str;
    }

    void printTree(Node* root, Trunk* prev, bool isLeft)
    {
        if (root == nullptr) {
            return;
        }

        string prev_str = "    ";
        Trunk* trunk = new Trunk(prev, prev_str);

        printTree(root->right, trunk, true);

        if (!prev) {
            trunk->str = "---";
        }
        else if (isLeft)
        {
            trunk->str = ".---";
            prev_str = "   |";
        }
        else {
            trunk->str = "`---";
            prev->str = prev_str;
        }

        showTrunks(trunk);
        cout << " " << root->key << endl;

        if (prev) {
            prev->str = prev_str;
        }
        trunk->str = "   |";

        printTree(root->left, trunk, false);
    }

    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    int getBalanceFactor(Node* node) {
        return getHeight(node->right) - getHeight(node->left);
    }

    void fixHeight(Node* node) {
        int hl = getHeight(node->left);
        int hr = getHeight(node->right);
        node->height = (hl > hr ? hl : hr) + 1;
    }

    Node* rotateRight(Node* node) {
        Node* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        fixHeight(node);
        fixHeight(newRoot);
        return newRoot;
    }

    Node* rotateLeft(Node* node) {
        Node* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        fixHeight(node);
        fixHeight(newRoot);
        return newRoot;
    }

    Node* balance(Node* node) {
        fixHeight(node);
        if (getBalanceFactor(node) == 2) {
            if (getBalanceFactor(node->right) < 0)
                node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        if (getBalanceFactor(node) == -2) {
            if (getBalanceFactor(node->left) > 0)
                node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        return node;
    }

    Node* insert(Node* node, int key) {
        if (!node)
            return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);
        return balance(node);
    }

    Node* findMin(Node* node) {
        return node->left ? findMin(node->left) : node;
    }

    Node* removeMin(Node* node) {
        if (!node->left)
            return node->right;
        node->left = removeMin(node->left);
        return balance(node);
    }

    Node* remove(Node* node, int key) {
        if (!node)
            return nullptr;
        if (key < node->key)
            node->left = remove(node->left, key);
        else if (key > node->key)
            node->right = remove(node->right, key);
        else {
            Node* leftChild = node->left;
            Node* rightChild = node->right;
            delete node;
            if (!rightChild)
                return leftChild;
            Node* minNode = findMin(rightChild);
            minNode->right = removeMin(rightChild);
            minNode->left = leftChild;
            return balance(minNode);
        }
        return balance(node);
    }

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    void inorderTraversal(Node* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << node->key << " ";
            inorderTraversal(node->right);
        }
    }

    void preorderTraversal(Node* node) {
        if (node) {
            cout << node->key << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void postorderTraversal(Node* node) {
        if (node) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->key << " ";
        }
    }

public:
    void show()
    {
        printTree(root, nullptr, false);

    }

    AVLTree() {
        root = nullptr;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    void clear() {
        clear(root);
        root = nullptr;
    }

    void inorderTraversal() {
        inorderTraversal(root);
        cout << endl;
    }

    void preorderTraversal() {
        preorderTraversal(root);
        cout << endl;
    }

    void postorderTraversal() {
        postorderTraversal(root);
        cout << endl;
    }
};
