#pragma once

#include <iostream>


class BiList
{
public:
	BiList();
	~BiList();

	void push_back(int data);
	int getSize() { return Size; };
	int& operator[](const int index);
	void pop_front();
	void clear();
	void push_front(int data);
	void insert(int data, int index);
	void removeAt(int index);
	void pop_back();
	void DeleAllOccurrences(int date);
	void DelintheFollowing(int date);
	void showlist(bool startfrom = 1);

private:

	
	class Node
	{
	public:
		Node* pNext;
		Node* pPrev;
		int data;
		Node(int data = int(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	int Size;//кол-во эл-ов в списке
	Node* head;//голова списка
	Node* tail;//хвост списка
};


BiList::BiList()//+
{
	Size = 0;
	head = tail = nullptr;
}


BiList::~BiList()//+
{
	clear();
}


void BiList::push_back(int data)//+
{
	if (head == nullptr)
	{
		head = tail = new Node(data);
	}
	else
	{
		Node* current = new Node(data);
		tail->pNext = current;
		current->pPrev = tail;
		tail = current;
	}
	Size++;
}


int& BiList::operator[](const int index)//+
{
	if ((Size / 2 - index) > 0)//1st half
	{
		int counter = 0;
		Node* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}
	else
	{
		int counter = Size;
		Node* current = this->tail;
		while (true)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pPrev;
			counter--;
		}
	}
}


void BiList::pop_front()//+
{
	if (Size == 0)
	{
		std::cout << "BiList is empty" << '\n';
	}
	else if (Size == 1) {
		Size--;
	}
	else
	{
		Node* temp = head;
		head = head->pNext;
		head->pPrev = nullptr;
		delete temp;
		Size--;
	}
}


inline void BiList::clear()//+
{
	while (Size)
		pop_front();
}


void BiList::push_front(int data)//+
{
	if (head == nullptr)
	{
		head = tail = new Node(data);
	}
	else
	{
		Node* current = new Node(data);
		head->pPrev = current;
		current->pNext = head;
		head = current;
	}
	Size++;
}


void BiList::insert(int data, int index)//+
{
	if (!index)
		push_front(data);
	else if (index == Size)
		push_back(data);
	else if (Size / 2 - index > 0)//1st half
	{
		Node* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		previous->pNext = new Node(data, previous->pNext, previous);
		Size++;

	}
	else//2nd half
	{
		Node* next = this->tail;

		for (int i = Size - 1; i >= index; i--)
		{
			next = next->pPrev;
		}
		next->pNext = new Node(data, next->pNext, next);
		next->pNext->pNext->pPrev = next->pNext;
		Size++;
	}
}


void BiList::removeAt(int index)//+
{
	if (!index)
		pop_front();
	else if (index == Size - 1)
		pop_back();
	else if (Size / 2 - index > 0)
	{
		Node* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;
		toDelete->pNext->pPrev = previous;
		delete toDelete;
		Size--;
	}
	else
	{
		Node* next = this->tail;

		for (int i = Size - 1; i > index + 1; i--)
		{
			next = next->pPrev;
		}

		Node* toDelete = next->pPrev;

		next->pPrev = toDelete->pPrev;
		toDelete->pPrev->pNext = next;

		delete toDelete;
		Size--;
	}
}


void BiList::DeleAllOccurrences(int date) {
	Node* current = head;
	while (current->pNext != nullptr) {
		if (current->data == date) {
			Node* delNode = current;
			if (current->pPrev == nullptr) {
				current = current->pNext;
				head = head->pNext;
				delete delNode;
				head->pPrev = nullptr;
				Size--;
			}
			else {
				current->pPrev->pNext = current->pNext;
				current->pNext->pPrev = current->pPrev;
				current = current->pNext;
				delete delNode;
				Size--;
			}

		}
		else {
			current = current->pNext;
		}
	}
	if (current->data == date) {
		tail = tail->pPrev;
		delete current;
		tail->pNext = nullptr;
		Size--;
	}
}


void BiList::DelintheFollowing(int date) {
	Node* current = head;
	while (current->pNext != nullptr) {
		if (current->data == date) {
			if (current->pNext->pNext != nullptr) {
				Node* delNode = current->pNext;
				current->pNext->pNext->pPrev = current;
				current->pNext = current->pNext->pNext;
				current = current->pNext;
				delete delNode;
				Size--;
			}
			else {
				Node* delNode = current->pNext;
				tail = tail->pPrev;
				delete delNode;
				tail->pNext = nullptr;
				Size--;
			}
		}
		else {
			current = current->pNext;
		}
	}

}


inline void BiList::pop_back()//+
{
	if (head == tail) {
		Size--;
	}
	else {
		Node* current = tail;
		tail->pPrev->pNext = nullptr;
		delete current;
		Size--;
	}

}




void BiList::showlist(bool startfrom)//1-head,0-tail//+
{
	if (Size == 0) {
		std::cout << "BiList is empty" << '\n';
	}
	else {
		if (startfrom)
		{
			Node* current = head;
			int i = 0;
			while (current != nullptr && i < Size)
			{
				std::cout << current->data << '\n';
				current = current->pNext;
				i++;
			}
		}
		else
		{
			Node* current = tail;
			int i = 0;
			while (current != nullptr && i < Size)
			{
				std::cout << current->data << '\n';
				current = current->pPrev;
				i++;
			}
		}
	}
}