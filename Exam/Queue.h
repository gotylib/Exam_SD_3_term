#pragma once


class Queue {
	
	class Node {
	public:
		int date;
		Node* pref;
		Node* next;
		Node() {
			pref = nullptr;
			next = nullptr;
		}
	};
	int size = 0;
	Node* head = new Node;
	Node* end = new Node;
public:
	void push_back(int date);
	void remove();
	int show();
	void clear();
	~Queue();
};


void Queue::push_back(int date) {
	if (size == 0) {
		head->next = end;
		end->pref = head;
		end->date = date;
		size++;
	}
	else if (size == 1) {
		head->date = end->date;
		end->date = date;
		size++;
	}
	else {
		Node* NewNode = new Node;
		head->next = NewNode;
		NewNode->pref = end->pref;
		end->pref = NewNode;
		NewNode->next = end;
		NewNode->date = end->date;
		end->date = date;
		size++;
	}

}


void Queue::remove() {
	if (size > 2) {
		Node* CurrentNode = new Node;
		CurrentNode = head;
		head = head->next;
		size--;
		delete CurrentNode;
	}
	else if (size <= 2) {
		size--;
		head->date = end->date;
	}

}


int Queue::show() {
	if (size > 0) {
		return head->date;
	}
	else {
		throw;
	}

}


void Queue::clear() {
	while (size > 2) {
		remove();
	}
}


Queue::~Queue() {
	clear();
}