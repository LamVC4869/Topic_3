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

bool check (int a, int b, int c) {
	return a * c == b;
}

struct LinkedList {
	node head = NULL;
	
	void push_back (node k) {
		if (head == NULL) {
			head = k;
			return;
		}
		node p = head;
		while (p->next != NULL) p = p->next;
		p->next = k;
	}
	int size () {
	    int count = 0;
	    node p = head;
	    while (p != NULL) {
	        count++;
	        p = p->next;
	    }
	    return count;
	}
	int quantity () {
	    if (size() < 3) return -1;
		node p = head;
		int count = 0;
		while (p->next->next != NULL) {
			if (check(p->data, p->next->data, p->next->next->data)) count++;
			p = p->next;
		}
		return count > 0 ? count : -1;
	}
	void display_index () {
		node p = head;
		int idx = 2;
		while (p->next->next != NULL) {
			if (check(p->data, p->next->data, p->next->next->data)) cout << idx << ' ';
			idx++;
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
	int n; cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		list.push_back(make_node(x));
	}
	cout << list.quantity() << '\n';
	if (list.quantity() == -1) return 0;
	list.display_index();
}
