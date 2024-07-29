#include "dll.h"
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

	Node* currentNode = head;

	while (currentNode != nullptr && currentNode->data != target) {
		currentNode = currentNode->next;
	}

	return currentNode;

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

void doubleLL::Remove(int value) {

	Node* currentNode = Find(value);

	if (currentNode != nullptr) {

		if (currentNode == head) {

			head = head->next;
			if (head == nullptr) {
				tail = nullptr;
			}
			else {
				head->prev = nullptr;
			}

		}
		else if (currentNode == tail) {

			tail = tail->prev;
			if (tail == nullptr) {
				head = nullptr;
			}
			else {
				tail->next = nullptr;
			}

		}
		else {
			currentNode->next->prev = currentNode->prev;
			currentNode->prev->next = currentNode->next;

		}

		delete currentNode;

	}
	else {
		cout << value << " not found" << endl;
	}

}

void doubleLL::Print() {

	Node* currentNode = head;

	if (currentNode == nullptr) {
		cout << "list is empty";
	}

	while (currentNode != nullptr) {
		cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}

	cout << endl;

}

void doubleLL::PrintReverse() {

	Node* currentNode = tail;

	if (currentNode == nullptr) {
		cout << "list is empty";
	}

	while (currentNode != nullptr) {
		cout << currentNode->data << " ";
		currentNode = currentNode->prev;
	}

	cout << endl;

}
