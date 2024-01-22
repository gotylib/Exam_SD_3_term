#include <stack>
#include <string>



/*
    дано выражение в постфиксной форме, вывести результат этого выражения c++
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
    1. Создать пустой стек.
2. Просмотреть каждый символ в выражении слева направо.
3. Если символ является операндом, то поместить его в стек.
4. Если символ является оператором, то извлечь из стека два операнда, выполнить операцию и поместить результат обратно в стек.
5. После просмотра всего выражения результат будет находиться на вершине стека.
Для вычисления значения выражения в постфиксной форме в данном примере используется функция evaluatePostfix, которая принимает строку с выражением и возвращает результат. Внутри функции создается стек operands, который будет хранить операнды. Затем каждый символ в выражении обрабатывается один за другим. Если символ является операндом, то он помещается в стек. Если символ является оператором, то из стека извлекаются два операнда, выполняется операция и результат помещается обратно в стек. После обработки всего выражения результат будет находиться на вершине стека и возвращается из функции. В данном примере рассматриваются четыре основных арифметических операции: сложение (+), вычитание (-), умножение (*) и деление (/).
*/


/*
* дано бинарное дерево из целых чисел, найти максимальный уровень дерева, на котором есть положительные элементы
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
    // Создаем бинарное дерево для тестирования
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
    Пусть имеется бинарное дерево Т. Сформировать два идеально сбалансированных дерева из отрицательных и неотрицательных элементов дерева Т. Вывести полученные деревья на экран.
*/
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root, vector<int>& neg, vector<int>& nonNeg) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left, neg, nonNeg);

    if (root->val < 0) {
        neg.push_back(root->val);
    } else {
        nonNeg.push_back(root->val);
    }

    inorder(root->right, neg, nonNeg);
}

TreeNode* buildBalancedBST(vector<int>& nums, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildBalancedBST(nums, start, mid - 1);
    root->right = buildBalancedBST(nums, mid + 1, end);
    return root;
}

int main() {
    // Создаем дерево и заполняем его данными
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(-4);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);

    // Обходим дерево и разделяем элементы на две группы
    vector<int> neg, nonNeg;
    inorder(root, neg, nonNeg);

    // Сортируем каждую группу по возрастанию
    sort(neg.begin(), neg.end());
    sort(nonNeg.begin(), nonNeg.end());

    // Строим два новых идеально сбалансированных дерева из отрицательных и неотрицательных элементов
    TreeNode* negRoot = buildBalancedBST(neg, 0, neg.size() - 1);
    TreeNode* nonNegRoot = buildBalancedBST(nonNeg, 0, nonNeg.size() - 1);

    // Выводим полученные деревья на экран
    cout << "Negative tree:" << endl;
    printTree(negRoot, 0);

    cout << "Non-negative tree:" << endl;
    printTree(nonNegRoot, 0);

    return 0;
}
*/
/*
 По кругу расположено N монет гербами вверх и М монет гербами вниз. Обходя круг по ходу часовой стрелки, переворачивает каждую S-тую монету. В первый раз счет начинается с герба. В каком порядке надо расставить монеты, чтобы после К ходов стало L монет, лежащих гербами вверх. 
*/
/*
Алгоритм решения данной задачи может выглядеть следующим образом:

Создаем переменные N и M и присваиваем им значения количества монет гербами вверх и вниз соответственно.
Создаем переменные K и L и присваиваем им значения количества ходов и количества монет, которые должны оказаться гербами вверх после этих ходов.
Создаем цикл, который будет повторяться K раз.
Внутри цикла создаем условие, проверяющее номер текущего хода. Если номер хода делится на S без остатка, то переворачиваем монету.
В зависимости от изначального положения монет и результатов переворотов находим порядок, в котором монеты должны быть расставлены, чтобы после K ходов было L монет гербами вверх. Это может быть сделано путем смещения границы между монетами гербами вверх и вниз.
Выводим порядок расстановки монет.
*/
/*#include <iostream>
using namespace std;

void flipCoins(int N, int M, int K, int L, int S) {
    // Создаем массив для хранения порядка расстановки монет
    char *coins = new char[N + M];
    // Инициализируем массив в соответствии с изначальным положением монет
    for (int i = 0; i < N; i++) {
        coins[i] = 'H'; // Герб вверх
    }
    for (int i = N; i < N + M; i++) {
        coins[i] = 'T'; // Герб вниз
    }
    // Переворачиваем монеты в соответствии с правилом
    for (int i = 1; i <= K; i++) {
        if (i % S == 0) {
            for (int j = 0; j < N + M; j++) {
                if (coins[j] == 'H') {
                    coins[j] = 'T'; // Герб вниз
                }
                else {
                    coins[j] = 'H'; // Герб вверх
                }
            }
        }
    }
    // Находим порядок расстановки монет, чтобы после K ходов было L монет гербами вверх
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
    cout << "Введите количество монет гербами вверх (N): ";
    cin >> N;
    cout << "Введите количество монет гербами вниз (M): ";
    cin >> M;
    cout << "Введите количество ходов (К): ";
    cin >> K;
    cout << "Введите количество монет гербами вверх после ходов (L): ";
    cin >> L;
    cout << "Введите номер каждого S-того хода для переворота монет: ";
    cin >> S;
    flipCoins(N, M, K, L, S);
    return 0;
}
/*

/*
* Деревья с обратной связью деревья где адрес Р1 вершины дерева типа ТNode, содержащей поля Data (целого типа), Left, Right и Parent (типа PNode указателя на TNode). Поля Left и Right указывают на дочерние вершины, а поле Parent на родительскую вершину данной вершины (если вершина является корнем дерева, то ее поле Parent равно nil
Даны указатели Р1, Р2, Р3 на три вершины дерева с обратной связью. Для каждой из данных вершин вывести ее уровень (корень дерева имеет уровень 0).
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

    node1 = root->Left;    // Пример узла Р1
    node2 = root->Right;   // Пример узла Р2
    node3 = root->Right->Right;   // Пример узла Р3

    std::cout << "Уровень узла Р1: " << tree.Level(node1) << std::endl;
    std::cout << "Уровень узла Р2: " << tree.Level(node2) << std::endl;
    std::cout << "Уровень узла Р3: " << tree.Level(node3) << std::endl;

    return 0;
}
*/
//1. Написать программу, которая создает очередь из слов, считываемых из файла(слова должны содержаться в очереди только в одном экземпляре).Вывести на экран эту очередь и подсчитать количество слов в ней.
/*
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_set>

int main() {
    std::queue<std::string> wordQueue;
    std::unordered_set<std::string> wordsSet;

    std::ifstream inputFile("input.txt"); // Замените "input.txt" на путь к вашему файлу

    if (inputFile.is_open()) {
        std::string word;

        // Считываем слова из файла
        while (inputFile >> word) {
            // Если слово еще не присутствует в множестве, то добавляем его в очередь и множество
            if (wordsSet.insert(word).second) {
                wordQueue.push(word);
            }
        }

        inputFile.close();

        // Печатаем содержимое очереди
        while (!wordQueue.empty()) {
            std::cout << wordQueue.front() << " ";
            wordQueue.pop();
        }

        std::cout << std::endl;
        std::cout << "Количество слов: " << wordsSet.size() << std::endl;
    } else {
        std::cout << "Не удалось открыть файл" << std::endl;
    }

    return 0;
}
*/
//2. Написать программу, которая создает бинарное дерево, удалить из бинарного дерева наименьшее количество вершин таким образом, чтобы полученное дерево было строго бинарным.Распечатать полученное дерево
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

    // Создаем бинарное дерево
    insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);

    cout << "Исходное дерево: ";
    inorderTraversal(root);

    // Удаляем минимальное количество вершин для получения строго бинарного дерева
    root = removeMinimum(root);

    cout << "\nПолученное дерево: ";
    inorderTraversal(root);

    return 0;
}
*/
/*
Написать программу, которая создает очередь целых чисел, считываемых из файла. Переставить элементы очереди так, чтобы вначале шли положительные числа (не меняя их взаимного расположения), а затем все остальные (не меняя их взаимного расположения)
*/
/*
    #include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    queue<int> positiveQueue;
    queue<int> negativeQueue;

    // Открываем файл для чтения
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

    // Объединяем очереди
    queue<int> resultQueue;
    while (!positiveQueue.empty()) {
        resultQueue.push(positiveQueue.front());
        positiveQueue.pop();
    }
    while (!negativeQueue.empty()) {
        resultQueue.push(negativeQueue.front());
        negativeQueue.pop();
    }

    // Выводим результат
    while (!resultQueue.empty()) {
        cout << resultQueue.front() << " ";
        resultQueue.pop();
    }

    return 0;
}

*/



/*
   Пусть имеется бинарное дерево Т. Сформировать два идеально сбалансированных дерева из отрицательных и неотрицательных элементов дерева Т. Вывести полученные деревья на экран.
*/

/*
    Для решения этой задачи можно использовать рекурсивный алгоритм. Нам нужно обходить дерево Т и добавлять элементы в две отдельные очереди: одну для отрицательных элементов, другую для неотрицательных. Затем мы можем построить два новых сбалансированных дерева из этих очередей.

Для построения сбалансированного дерева можно использовать следующий алгоритм:

1. Получить размер очереди.
2. Если размер равен 0, вернуть nullptr.
3. Иначе:
   1. Получить индекс середины очереди.
   2. Создать новый узел дерева, значение которого равно значению элемента с индексом середины.
   3. Рекурсивно построить левое поддерево из элементов с индексами от 0 до середины - 1.
   4. Рекурсивно построить правое поддерево из элементов с индексами от середины + 1 до конца очереди.
   5. Вернуть созданный узел.
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
    // Создаем бинарное дерево
    Node* root = new Node(3);
    root->left = new Node(-2);
    root->right = new Node(5);
    root->left->left = new Node(-1);
    root->left->right = new Node(0);
    root->right->left = new Node(4);

    // Разделяем дерево на две очереди
    queue<int> positiveQueue;
    queue<int> negativeQueue;
    splitTree(root, positiveQueue, negativeQueue);

    // Строим два сбалансированных дерева
    Node* positiveTree = buildBalancedTree(positiveQueue, 0, positiveQueue.size() - 1);
    Node* negativeTree = buildBalancedTree(negativeQueue, 0, negativeQueue.size() - 1);

    // Выводим полученные деревья на экран
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
 Написать программу, которая считывает целые числа с клавиатуры и создает стек, содержащий двоичные эквиваленты этих чисел. Вывести полученный стек на экран.
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
