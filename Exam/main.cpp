#include <stack>
#include <string>



/*
    ���� ��������� � ����������� �����, ������� ��������� ����� ��������� c++
*/

/*int evaluatePostfix(string expression) {
    stack<int> operands;

    for (char c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0');
        }
        else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            switch (c) {
            case '+':
                operands.push(operand1 + operand2);
                break;
            case '-':
                operands.push(operand1 - operand2);
                break;
            case '*':
                operands.push(operand1 * operand2);
                break;
            case '/':
                operands.push(operand1 / operand2);
                break;
            }
        }
    }

    return operands.top();
}
*/
/*
    int main() {
    string expression = "23+4*";
    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;
    return 0;
}
*/

/*
    1. ������� ������ ����.
2. ����������� ������ ������ � ��������� ����� �������.
3. ���� ������ �������� ���������, �� ��������� ��� � ����.
4. ���� ������ �������� ����������, �� ������� �� ����� ��� ��������, ��������� �������� � ��������� ��������� ������� � ����.
5. ����� ��������� ����� ��������� ��������� ����� ���������� �� ������� �����.
��� ���������� �������� ��������� � ����������� ����� � ������ ������� ������������ ������� evaluatePostfix, ������� ��������� ������ � ���������� � ���������� ���������. ������ ������� ��������� ���� operands, ������� ����� ������� ��������. ����� ������ ������ � ��������� �������������� ���� �� ������. ���� ������ �������� ���������, �� �� ���������� � ����. ���� ������ �������� ����������, �� �� ����� ����������� ��� ��������, ����������� �������� � ��������� ���������� ������� � ����. ����� ��������� ����� ��������� ��������� ����� ���������� �� ������� ����� � ������������ �� �������. � ������ ������� ��������������� ������ �������� �������������� ��������: �������� (+), ��������� (-), ��������� (*) � ������� (/).
*/


/*
* ���� �������� ������ �� ����� �����, ����� ������������ ������� ������, �� ������� ���� ������������� ��������
*/
/*
 #include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxLevelWithPositive(TreeNode* root) {
    int maxLevel = 0;
    dfs(root, 1, maxLevel);
    return maxLevel;
}

void dfs(TreeNode* node, int level, int& maxLevel) {
    if (node == nullptr) {
        return;
    }

    if (node->val > 0) {
        maxLevel = max(maxLevel, level);
    }

    dfs(node->left, level + 1, maxLevel);
    dfs(node->right, level + 1, maxLevel);
}

int main() {
    // ������� �������� ������ ��� ������������
    TreeNode* root = new TreeNode(-1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(-4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(-7);

    int maxLevel = maxLevelWithPositive(root);
    cout << "Max level with positive elements: " << maxLevel << endl;

    return 0;
}
*/

/*
    ����� ������� �������� ������ �. ������������ ��� �������� ���������������� ������ �� ������������� � ��������������� ��������� ������ �. ������� ���������� ������� �� �����.
*/
/*
 �� ����� ����������� N ����� ������� ����� � � ����� ������� ����. ������ ���� �� ���� ������� �������, �������������� ������ S-��� ������. � ������ ��� ���� ���������� � �����. � ����� ������� ���� ���������� ������, ����� ����� � ����� ����� L �����, ������� ������� �����. 
*/
/*
�������� ������� ������ ������ ����� ��������� ��������� �������:

������� ���������� N � M � ����������� �� �������� ���������� ����� ������� ����� � ���� ��������������.
������� ���������� K � L � ����������� �� �������� ���������� ����� � ���������� �����, ������� ������ ��������� ������� ����� ����� ���� �����.
������� ����, ������� ����� ����������� K ���.
������ ����� ������� �������, ����������� ����� �������� ����. ���� ����� ���� ������� �� S ��� �������, �� �������������� ������.
� ����������� �� ������������ ��������� ����� � ����������� ����������� ������� �������, � ������� ������ ������ ���� �����������, ����� ����� K ����� ���� L ����� ������� �����. ��� ����� ���� ������� ����� �������� ������� ����� �������� ������� ����� � ����.
������� ������� ����������� �����.
*/
/*#include <iostream>
using namespace std;

void flipCoins(int N, int M, int K, int L, int S) {
    // ������� ������ ��� �������� ������� ����������� �����
    char *coins = new char[N + M];
    // �������������� ������ � ������������ � ����������� ���������� �����
    for (int i = 0; i < N; i++) {
        coins[i] = 'H'; // ���� �����
    }
    for (int i = N; i < N + M; i++) {
        coins[i] = 'T'; // ���� ����
    }
    // �������������� ������ � ������������ � ��������
    for (int i = 1; i <= K; i++) {
        if (i % S == 0) {
            for (int j = 0; j < N + M; j++) {
                if (coins[j] == 'H') {
                    coins[j] = 'T'; // ���� ����
                }
                else {
                    coins[j] = 'H'; // ���� �����
                }
            }
        }
    }
    // ������� ������� ����������� �����, ����� ����� K ����� ���� L ����� ������� �����
    int count = 0;
    for (int i = 0; i < N + M; i++) {
        if (coins[i] == 'H') {
            cout << "H ";
            count++;
        }
        if (count == L) {
            break;
        }
    }
    for (int i = 0; i < N + M; i++) {
        if (coins[i] == 'T') {
            cout << "T ";
        }
    }
    cout << endl;
    delete coins;
}

int main() {
    int N, M, K, L, S;
    cout << "������� ���������� ����� ������� ����� (N): ";
    cin >> N;
    cout << "������� ���������� ����� ������� ���� (M): ";
    cin >> M;
    cout << "������� ���������� ����� (�): ";
    cin >> K;
    cout << "������� ���������� ����� ������� ����� ����� ����� (L): ";
    cin >> L;
    cout << "������� ����� ������� S-���� ���� ��� ���������� �����: ";
    cin >> S;
    flipCoins(N, M, K, L, S);
    return 0;
}
/*

/*
* ������� � �������� ������ ������� ��� ����� �1 ������� ������ ���� �Node, ���������� ���� Data (������ ����), Left, Right � Parent (���� PNode ��������� �� TNode). ���� Left � Right ��������� �� �������� �������, � ���� Parent �� ������������ ������� ������ ������� (���� ������� �������� ������ ������, �� �� ���� Parent ����� nil
���� ��������� �1, �2, �3 �� ��� ������� ������ � �������� ������. ��� ������ �� ������ ������ ������� �� ������� (������ ������ ����� ������� 0).
*/
/*
#include <iostream>

struct TNode {
    int Data;
    TNode *Left;
    TNode *Right;
    TNode *Parent;

    TNode(int data) : Data(data), Left(nullptr), Right(nullptr), Parent(nullptr) {}
};

class BinaryTree {
public:
    void Insert(TNode *&root, int data) {
        if (root == nullptr) {
            root = new TNode(data);
        } else {
            if (data < root->Data) {
                Insert(root->Left, data);
                root->Left->Parent = root;
            } else {
                Insert(root->Right, data);
                root->Right->Parent = root;
            }
        }
    }

    int Level(TNode *node) {
        if (node == nullptr)
            return -1;

        int level = 0;
        while (node->Parent != nullptr) {
            node = node->Parent;
            level++;
        }
        return level;
    }
};

int main() {
    BinaryTree tree;
    TNode *root = nullptr;
    TNode *node1 = nullptr;
    TNode *node2 = nullptr;
    TNode *node3 = nullptr;

    tree.Insert(root, 4);
    tree.Insert(root, 2);
    tree.Insert(root, 6);
    tree.Insert(root, 1);
    tree.Insert(root, 3);
    tree.Insert(root, 5);
    tree.Insert(root, 7);

    node1 = root->Left;    // ������ ���� �1
    node2 = root->Right;   // ������ ���� �2
    node3 = root->Right->Right;   // ������ ���� �3

    std::cout << "������� ���� �1: " << tree.Level(node1) << std::endl;
    std::cout << "������� ���� �2: " << tree.Level(node2) << std::endl;
    std::cout << "������� ���� �3: " << tree.Level(node3) << std::endl;

    return 0;
}
*/
//1. �������� ���������, ������� ������� ������� �� ����, ����������� �� �����(����� ������ ����������� � ������� ������ � ����� ����������).������� �� ����� ��� ������� � ���������� ���������� ���� � ���.
/*
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_set>

int main() {
    std::queue<std::string> wordQueue;
    std::unordered_set<std::string> wordsSet;

    std::ifstream inputFile("input.txt"); // �������� "input.txt" �� ���� � ������ �����

    if (inputFile.is_open()) {
        std::string word;

        // ��������� ����� �� �����
        while (inputFile >> word) {
            // ���� ����� ��� �� ������������ � ���������, �� ��������� ��� � ������� � ���������
            if (wordsSet.insert(word).second) {
                wordQueue.push(word);
            }
        }

        inputFile.close();

        // �������� ���������� �������
        while (!wordQueue.empty()) {
            std::cout << wordQueue.front() << " ";
            wordQueue.pop();
        }

        std::cout << std::endl;
        std::cout << "���������� ����: " << wordsSet.size() << std::endl;
    } else {
        std::cout << "�� ������� ������� ����" << std::endl;
    }

    return 0;
}
*/
//2. �������� ���������, ������� ������� �������� ������, ������� �� ��������� ������ ���������� ���������� ������ ����� �������, ����� ���������� ������ ���� ������ ��������.����������� ���������� ������
/*
 #include<iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = right = nullptr;
    }
};

void insert(TreeNode* &root, int data) {
    if (root == nullptr) {
        root = new TreeNode(data);
    }
    else if (data < root->data) {
        insert(root->left, data);
    }
    else {
        insert(root->right, data);
    }
}

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

TreeNode* removeMinimum(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    else if (root->left == nullptr) {
        TreeNode* temp = root->right;
        delete root;
        return temp;
    }
    else {
        root->left = removeMinimum(root->left);
        return root;
    }
}

int main() {
    TreeNode* root = nullptr;

    // ������� �������� ������
    insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);

    cout << "�������� ������: ";
    inorderTraversal(root);

    // ������� ����������� ���������� ������ ��� ��������� ������ ��������� ������
    root = removeMinimum(root);

    cout << "\n���������� ������: ";
    inorderTraversal(root);

    return 0;
}
*/
/*
 ��� ������� ���� ������ ����� ������������ ��� �������: ���� ��� ������������� �����, ������ ��� �������������. ��������� ����� �� ����� � ��������� �� � ��������������� �������. ����� ���������� ������� � ����, ������� �������� ��� �������� �� ������� ������������� �����, � ����� ��� �������� �� ������� ������������� �����.
*/
/*
    #include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    queue<int> positiveQueue;
    queue<int> negativeQueue;

    // ��������� ���� ��� ������
    ifstream inputFile("input.txt");

    int number;
    while (inputFile >> number) {
        if (number > 0) {
            positiveQueue.push(number);
        } else {
            negativeQueue.push(number);
        }
    }

    inputFile.close();

    // ���������� �������
    queue<int> resultQueue;
    while (!positiveQueue.empty()) {
        resultQueue.push(positiveQueue.front());
        positiveQueue.pop();
    }
    while (!negativeQueue.empty()) {
        resultQueue.push(negativeQueue.front());
        negativeQueue.pop();
    }

    // ������� ���������
    while (!resultQueue.empty()) {
        cout << resultQueue.front() << " ";
        resultQueue.pop();
    }

    return 0;
}

*/



/*
   ����� ������� �������� ������ �. ������������ ��� �������� ���������������� ������ �� ������������� � ��������������� ��������� ������ �. ������� ���������� ������� �� �����.
*/

/*
    ��� ������� ���� ������ ����� ������������ ����������� ��������. ��� ����� �������� ������ � � ��������� �������� � ��� ��������� �������: ���� ��� ������������� ���������, ������ ��� ���������������. ����� �� ����� ��������� ��� ����� ���������������� ������ �� ���� ��������.

��� ���������� ����������������� ������ ����� ������������ ��������� ��������:

1. �������� ������ �������.
2. ���� ������ ����� 0, ������� nullptr.
3. �����:
   1. �������� ������ �������� �������.
   2. ������� ����� ���� ������, �������� �������� ����� �������� �������� � �������� ��������.
   3. ���������� ��������� ����� ��������� �� ��������� � ��������� �� 0 �� �������� - 1.
   4. ���������� ��������� ������ ��������� �� ��������� � ��������� �� �������� + 1 �� ����� �������.
   5. ������� ��������� ����.
*/
/*
    #include <iostream>
#include <queue>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

void splitTree(Node* root, queue<int>& positiveQueue, queue<int>& negativeQueue) {
    if (root == nullptr) {
        return;
    }

    if (root->value >= 0) {
        positiveQueue.push(root->value);
    } else {
        negativeQueue.push(root->value);
    }

    splitTree(root->left, positiveQueue, negativeQueue);
    splitTree(root->right, positiveQueue, negativeQueue);
}

Node* buildBalancedTree(queue<int>& q, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node* root = new Node(q.front());
    q.pop();
    root->left = buildBalancedTree(q, start, mid - 1);
    root->right = buildBalancedTree(q, mid + 1, end);

    return root;
}

void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    printTree(root->left);
    cout << root->value << " ";
    printTree(root->right);
}

int main() {
    // ������� �������� ������
    Node* root = new Node(3);
    root->left = new Node(-2);
    root->right = new Node(5);
    root->left->left = new Node(-1);
    root->left->right = new Node(0);
    root->right->left = new Node(4);

    // ��������� ������ �� ��� �������
    queue<int> positiveQueue;
    queue<int> negativeQueue;
    splitTree(root, positiveQueue, negativeQueue);

    // ������ ��� ���������������� ������
    Node* positiveTree = buildBalancedTree(positiveQueue, 0, positiveQueue.size() - 1);
    Node* negativeTree = buildBalancedTree(negativeQueue, 0, negativeQueue.size() - 1);

    // ������� ���������� ������� �� �����
    cout << "Positive tree: ";
    printTree(positiveTree);
    cout << endl;

    cout << "Negative tree: ";
    printTree(negativeTree);
    cout << endl;

    return 0;
}
*/
/*
 �������� ���������, ������� ��������� ����� ����� � ���������� � ������� ����, ���������� �������� ����������� ���� �����. ������� ���������� ���� �� �����.
*/

/*
    #include <iostream>
#include <set>

struct Node {
    char data;
    Node* left;
    Node* right;
};

void insertNode(Node*& root, char value) {
    if (root == nullptr) {
        root = new Node;
        root->data = value;
        root->left = nullptr;
        root->right = nullptr;
    }
    else {
        if (value < root->data) {
            insertNode(root->left, value);
        }
        else if (value > root->data) {
            insertNode(root->right, value);
        }
    }
}

void printInOrder(Node* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        std::cout << root->data << " ";
        printInOrder(root->right);
    }
}

int countDigits(Node* root) {
    std::set<char> digits;
    countDigitsHelper(root, digits);
    return digits.size();
}

void countDigitsHelper(Node* root, std::set<char>& digits) {
    if (root != nullptr) {
        countDigitsHelper(root->left, digits);
        if (isdigit(root->data)) {
            digits.insert(root->data);
        }
        countDigitsHelper(root->right, digits);
    }
}

int main() {
    Node* root = nullptr;
    char input;
    
    std::cout << "Enter characters (press enter to quit):\n";
    while (std::cin >> input) {
        insertNode(root, input);
    }
    
    std::cout << "Characters in ascending order: ";
    printInOrder(root);
    std::cout << std::endl;
    
    int digitCount = countDigits(root);
    std::cout << "Number of digits: " << digitCount << std::endl;
    
    return 0;
}
*/