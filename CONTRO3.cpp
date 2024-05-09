#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

typedef Node* node;

node make_node (int x) {
	node p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}

struct LinkedList {
	node head = NULL;
	
	void push_back (node p) {
		if (head == NULL) {
			head = p;
			return;
		}
		node curr = head;
		while (curr->next != NULL) curr = curr->next;
		curr->next = p;
	}
	int size () {
		int count = 0;
		node p = head;
		while (p != NULL) {
			++count;
			p = p->next;
		}
		return count;
	}
	void push_front (node p) {
		if (head == NULL) {
			head = p;
			return;
		}
		p->next = head;
		head = p;
	}
	void push (node k, int pos) {
		if (pos == 1) {
			push_front(k);
			return;
		}
		node curr = head;
		for (int i = 1; i <= pos - 2; i++) curr = curr->next;
		k->next = curr->next;
		curr->next = k;
	}
	void print () {
		node p = head;
		while (p != NULL) {
			cout << p->data << ' ';
			p = p->next;
		}
	}
	~LinkedList () {
		node p = NULL;
		while (head != NULL) {
			p = head;
			head = head->next;
			delete p;
		}
	}
};

int main () {
	LinkedList list;
	int n, a, k; cin >> n >> a >> k;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		list.push_back(make_node(x));
	}
	list.push(make_node(a), k);
	cout << list.size() << '\n';
	list.print();
}
