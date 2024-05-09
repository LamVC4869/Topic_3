#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

typedef Node* node;

node make_node (int x) {
	node p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}

bool check (int a, int b, int c) {
	return a == b + c || b == a + c || a + b == c;
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
	string result () {
		node left = head;
		while (left->next->next != NULL) {
			node mid = left->next;
			while (mid->next != NULL) {
				node right = mid->next;
				while (right != NULL) {
					if (check(left->data, mid->data, right->data)) return "YES";
					right = right->next;
				}
				mid = mid->next;
			}
			left = left->next;
		}
		return "NO";
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
	cout << list.result();
}
