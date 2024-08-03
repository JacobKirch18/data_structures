#pragma once

#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
	T data;
	Node* next;
	Node* prev;

	Node(T);
};

template<typename T>
class doubleLL {
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* Find(T);

public:
	doubleLL();
	~doubleLL();
	void InsertAtEnd(T);
	void InsertAtFront(T);
	void InsertAfter(T, T);
	void Remove(T);
	void Print();
	void PrintReverse();
};

template<typename T>
Node<T>::Node(T value) {

	data = value;
	next = prev = nullptr;

}

template<typename T>
doubleLL<T>::doubleLL() {

	head = tail = nullptr;

}

template<typename T>
doubleLL<T>::~doubleLL() {

	Node<T>* current_node = head;

	while (current_node != nullptr) {

		Node<T>* to_be_deleted = current_node;
		current_node = current_node->next;
		delete to_be_deleted;

	}

	head = tail = nullptr;

}

// helper function to find a value in the list
template<typename T>
Node<T>* doubleLL<T>::Find(T target) {

	Node<T>* current_node = head;

	while (current_node != nullptr && current_node->data != target) {
		current_node = current_node->next;
	}

	return current_node;

}

template<typename T>
void doubleLL<T>::InsertAtEnd(T value) {

	Node<T>* new_node = new Node<T>(value);

	if (head == nullptr) {
		head = tail = new_node;
	}
	else {

		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;

	}

}

template<typename T>
void doubleLL<T>::InsertAtFront(T value) {


	Node<T>* new_node = new Node(value);

	if (head == nullptr) {
		head = tail = new_node;
	}
	else {

		new_node->next = head;
		head = new_node;

	}

}

template<typename T>
void doubleLL<T>::InsertAfter(T value, T location) {

	Node<T>* current_node = Find(location);
	Node<T>* new_node = new Node<T>(value);

	if (current_node != tail) {

		new_node->next = current_node->next;
		new_node->prev = current_node;
		current_node->next->prev = new_node;
		current_node->next = new_node;

	}
	else if (current_node == tail) {

		new_node->prev = current_node;
		current_node->next = new_node;
		tail = new_node;

	}

}

template<typename T>
void doubleLL<T>::Remove(T value) {

	Node<T>* current_node = Find(value);

	if (current_node != nullptr) {

		if (current_node == head) {

			head = head->next;
			if (head == nullptr) {
				tail = nullptr;
			}
			else {
				head->prev = nullptr;
			}

		}
		else if (current_node == tail) {

			tail = tail->prev;
			if (tail == nullptr) {
				head = nullptr;
			}
			else {
				tail->next = nullptr;
			}

		}
		else {
			current_node->next->prev = current_node->prev;
			current_node->prev->next = current_node->next;

		}

		delete current_node;

	}
	else {
		cout << value << " not found" << endl;
	}

}

template<typename T>
void doubleLL<T>::Print() {

	Node<T>* current_node = head;

	if (current_node == nullptr) {
		cout << "list is empty";
	}

	while (current_node != nullptr) {
		cout << current_node->data << " ";
		current_node = current_node->next;
	}

	cout << endl;

}

template<typename T>
void doubleLL<T>::PrintReverse() {

	Node<T>* current_node = tail;

	if (current_node == nullptr) {
		cout << "list is empty";
	}

	while (current_node != nullptr) {
		cout << current_node->data << " ";
		current_node = current_node->prev;
	}

	cout << endl;

}
