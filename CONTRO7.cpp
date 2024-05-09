#include <iostream>
#include <fstream>
#include <cmath>

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

int distance (int a, int b) {
	return abs(a - b);
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
	int min_distance () {
		node p = head;
		int total = distance(p->data, p->next->data);
		while (p->next != NULL) {
			node pNext = p->next;
			while (pNext != NULL) {
				total = min(total, distance(p->data, pNext->data));
				pNext = pNext->next;
			}
			p = p->next;
		}
		return total;
	}
	int quantity_legal () {
		node p = head;
		int count = 0, total = min_distance();
		while (p->next != NULL) {
			node pNext = p->next;
			while (pNext != NULL) {
				if (distance(p->data, pNext->data) == total) count++;
				pNext = pNext->next;
			}
			p = p->next;
		}
		return count;
	}
	void display () {
		node p = head;
		int total = min_distance();
		while (p->next != NULL) {
			node pNext = p->next;
			while (pNext != NULL) {
				if (distance(p->data, pNext->data) == total) {
					int x = min(p->data, pNext->data), y = max(p->data, pNext->data);
					cout << '(' << x << ", " << y << ") ";
				}
				pNext = pNext->next;
			}
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
	freopen("CONTRO.inp", "r", stdin);
	freopen("CONTRO.out", "w", stdout);
	LinkedList list;
	int n; cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		list.push_back(make_node(x));
	}
	cout << list.quantity_legal() << ' ' << list.min_distance() << '\n';
	list.display();
}
