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

void push_back(node &head, node k) {
    if (head == NULL) {
        head = k;
        return;
    }
    node p = head;
    while (p->next != NULL) p = p->next;
    p->next = k;
}

int Max (node head) {
    int val = head->data;
    node p = head->next;
    while (p != NULL) {
        val = max(val, p->data);
        p = p->next;
    }
    return val;
}

int Min (node head) {
    int val = head->data;
    node p = head->next;
    while (p != NULL) {
        val = min(val, p->data);
        p = p->next;
    }
    return val;
}

void index_max (node head) {
    node p = head;
    int idx = 1, total = Max(head);
    while (p != NULL) {
        if (p->data == total) cout << idx << ' ';
        idx++;
        p = p->next;
    }
    cout << '\n';
}

void index_min (node head) {
    node p = head;
    int idx = 1, total = Min(head);
    while (p != NULL) {
        if (p->data == total) cout << idx << ' ';
        idx++;
        p = p->next;
    }
    cout << '\n';
}

int main () {
    node root = NULL;
    int n; cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        push_back(root, make_node(x));
    }
    cout << Max(root) << '\n';
    index_max(root);
    cout << Min(root) << '\n';
    index_min(root);
}
