#pragma once

class Node
{
public:
	int data;
	Node* next;
	Node* prev;

	Node(int);
};

class doubleLL
{
private:
	Node* head;
	Node* tail;
	Node* Find(int);

public:
	doubleLL();
	~doubleLL();
	void Insert(int);
	void Remove(int);
	void Print();
	void PrintReverse();
};

