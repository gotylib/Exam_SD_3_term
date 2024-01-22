#pragma once
 

class Stack {
private:
	
	class Node {
	public:
		int date;
		Node* ptr;
	};
	int size = 0;
	Node* head = new Node;
public:

	//Добавление элемента в начало стека
	void add(int date);

	//Показ элемента вершины стека
	int show();

	//Удаление элемента вершины стека
	void remove();

	//Отчистка стека
	void clear();

	Stack(int* arr, int score);

	Stack();

	~Stack();
};


Stack::Stack(int* arr, int score) {
	for (int i = 0; i < score; ++i) {
		if (size == 0) {
			head->date = arr[i];
			size++;
		}
		else {
			Node* NewNode = new Node;
			NewNode->ptr = head->ptr;
			NewNode->date = head->date;
			head->ptr = NewNode;
			head->date = arr[i];
			size++;
		}
	}
}


Stack::Stack() {

}



void Stack::add(int date) {
	if (head->ptr == nullptr && size == 0) {
		head = new Node;
		head->date = date;
		size++;
	}
	else {
		Node* NewNode = new Node;
		NewNode->ptr = head->ptr;
		NewNode->date = head->date;
		head->ptr = NewNode;
		head->date = date;
		size++;
	}
}


void Stack::remove() {
	if (head->ptr == nullptr) {
		size--;
	}
	else {
		Node* CurrentNode = new Node;
		CurrentNode = head;
		head = head->ptr;
		delete CurrentNode;
		size--;
	}
}


void Stack::clear() {
	while (size > 0) {
		remove();
	}
}


int Stack::show() {
	if (size == 0) {
		throw;
	}
	else {
		return head->date;
	}

}


Stack::~Stack() {
	clear();
}