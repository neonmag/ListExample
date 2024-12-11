#include <iostream>

using namespace std;

template <typename T>
class List {
	struct Node {
		Node* next;
		T value;
		int index;

		Node(T value, int index) {
			this->value = value;
			next = nullptr;
			this->index = index;
		}
	};

	Node* current;
	int size = 0;

	T findElement(Node* next, T value) { // find index by value
		if (next->value == value) {
			return next->index;
		}
		else if(next->next != nullptr) {
			return findElement(next->next, value);
		}
	}

	Node* findElementPtr(Node* prev, Node* next, T value) { // remove by value
		if (next->value == value) {
			prev->next = next->next;

			Node* temp = next->next;

			delete[] next;
			while (temp != nullptr) {
				temp->index--;
				temp = temp->next;
			}
			size--;
			return temp;
		}
		else if(next->next != nullptr) {
			return findElementPtr(next, next->next, value);
		}
	}

	Node* findIndexElementPtr(Node* prev, Node* next, int value) { // remove by index
		if (next->index == value) {
			prev->next = next->next;

			Node* temp = next->next;

			delete[] next;
			while (temp != nullptr) {
				temp->index--;
				temp = temp->next;
			}
			size--;
			return temp;
		}
		else if(next->next != nullptr) {
			return findIndexElementPtr(next, next->next, value);
		}
	}

	Node* findElementPtrValue(Node* next, T value) { // find element by value
		if (next->value == value) {
			return next;
		}
		else if(next->next != nullptr) {
			return findElementPtrValue(next->next, value);
		}
	}

public:
	List() {
		this->current = nullptr;
	}

	void append(T value) { // add
		if (size == 0) {
			this->current = new Node(value, 0);
			size++;
			return;
		}
		Node* newElement = new Node(value, size);
		Node* temp = current;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newElement;
		temp = newElement;

		size++;
	}

	T getByValue(T value) { // find by value
		if (current->value == value) {
			return current->index;
		}
		else {
			return findElement(current->next, value);
		}
	}

	Node* remove(T value) { // remove by value
		if (current->value == value) {
			return current;
		}
		else {
			return findElementPtr(current, current->next, value);
		}
	}

	Node* removeByIndex(int value) { // remove by index
		if (current->index == value) {
			return current;
		}
		else {
			return findIndexElementPtr(current, current->next, value);
		}
	}

	Node * getNext(Node * element){ // getr next element from choosen
		if (element->next != nullptr) {
			return element->next;
		}
		else {
			return element;
		}
	}

	Node* getElement(T value) { // get element by value
		if (current->value == value) {
			return current;
		}
		else {
			return findElementPtrValue(current->next, value);
		}
	}

	Node* pushBack(T value) { // insert element into start
		Node* newElement = new Node(value, 0);
		Node* temp = current;
		while (temp != nullptr) {
			if (temp->index == 0) {
				newElement->next = temp;
			}
			temp->index++;
			temp = temp->next;
		}

		current = newElement;

		return current;
	}

};

int main()
{
	List<int> obj;
	obj.append(12);
	obj.append(14);
	obj.append(125);
	obj.append(122);
	obj.append(1235);
	obj.append(1255);
	obj.append(12125);

	//cout << obj.getByValue(125) << endl;
	//obj.remove(14);
	//
	//cout << obj.getByValue(125);

	//obj.removeByIndex(3);
	//
	//auto element = obj.getElement(1255);
	//auto newElement = obj.getNext(element);
	auto pushBackElement = obj.pushBack(1);

	cout << pushBackElement->value << endl;
	cout << pushBackElement->index << endl;
	cout << obj.getByValue(12125);

	// next
	// value

	// getNext() +
	// search() +
	// remove() +
	// append() +
	// removeByIndex() +
	// push_back()  +
	// insert() by index
	// pop_back()
	// reverse()
}