#include "doubleLL.h"
#include <iostream>
using namespace std;

Node::Node(int value) {

	data = value;
	next = prev = nullptr;

}

doubleLL::doubleLL() {

	head = tail = nullptr;

}

doubleLL::~doubleLL() {

	Node* current_node = head;

	while (current_node != nullptr) {
		
		Node* to_be_deleted = current_node;
		current_node = current_node->next;
		delete to_be_deleted;

	}

	head = tail = nullptr;

}

// helper function to find a value in the list
Node* doubleLL::Find(int target) {

	Node* current_node = head;

	while (current_node != nullptr && current_node->data != target) {
		current_node = current_node->next;
	}

	return current_node;

}

void doubleLL::InsertAtEnd(int value) {

	Node* new_node = new Node(value);

	if (head == nullptr) {
		head = tail = new_node;
	}
	else {

		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;

	}

}

void doubleLL::InsertAtFront(int value) {


	Node* new_node = new Node(value);

	if (head == nullptr) {
		head = tail = new_node;
	}
	else {

		new_node->next = head;
		head = new_node;

	}

}

void doubleLL::InsertAfter(int value, int location) {

	Node* current_node = Find(location);
	Node* new_node = new Node(value);

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

void doubleLL::Remove(int value) {

	Node* current_node = Find(value);

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

void doubleLL::Print() {

	Node* current_node = head;

	if (current_node == nullptr) {
		cout << "list is empty";
	}

	while (current_node != nullptr) {
		cout << current_node->data << " ";
		current_node = current_node->next;
	}

	cout << endl;

}

void doubleLL::PrintReverse() {

	Node* current_node = tail;

	if (current_node == nullptr) {
		cout << "list is empty";
	}

	while (current_node != nullptr) {
		cout << current_node->data << " ";
		current_node = current_node->prev;
	}

	cout << endl;

}
