#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    int level;
    Node* left;
    Node* right;

    Node(int value, int lev) {
        level = lev;
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BiTree {
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
        cout << " " << root->data << endl;

        if (prev) {
            prev->str = prev_str;
        }
        trunk->str = "   |";

        printTree(root->left, trunk, false);
    }


    void insertRecursive(Node* currentNode, int value, int lev) {
        if (value < currentNode->data) {
            if (currentNode->left == nullptr) {
                currentNode->left = new Node(value,lev);
            }
            else {
                insertRecursive(currentNode->left, value,lev+1);
            }
        }
        else {
            if (currentNode->right == nullptr) {
                currentNode->right = new Node(value,lev);
            }
            else {
                insertRecursive(currentNode->right, value,lev+1);
            }
        }
    }

    Node* findMinValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* deleteRecursive(Node* currentNode, int value) {
        if (currentNode == nullptr) {
            return currentNode;
        }

        if (value < currentNode->data) {
            currentNode->left = deleteRecursive(currentNode->left, value);
        }
        else if (value > currentNode->data) {
            currentNode->right = deleteRecursive(currentNode->right, value);
        }
        else {
            if (currentNode->left == nullptr) {
                Node* temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else if (currentNode->right == nullptr) {
                Node* temp = currentNode->left;
                delete currentNode;
                return temp;
            }

            Node* temp = findMinValueNode(currentNode->right);
            currentNode->data = temp->data;
            currentNode->right = deleteRecursive(currentNode->right, temp->data);
        }

        return currentNode;
    }

    void printRecursive(Node* currentNode) {
        if (currentNode != nullptr) {
            printRecursive(currentNode->left);
            std::cout << currentNode->data << " ";
            printRecursive(currentNode->right);
        }
    }

    void clearRecursive(Node* currentNode) {
        if (currentNode != nullptr) {
            clearRecursive(currentNode->left);
            clearRecursive(currentNode->right);
            delete currentNode;
        }
    }
public:
    void show()
    {
        printTree(root, nullptr, false);

    }

    BiTree() {
        root = nullptr;
    }

    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value,0);
        }
        else {
            int lev = 1;
            insertRecursive(root, value,lev);
        }
    }

    void remove(int value) {
        root = deleteRecursive(root, value);
    }

    void print() {
        printRecursive(root);
        std::cout << std::endl;
    }

    void clear() {
        clearRecursive(root);
        root = nullptr;
    }
};

