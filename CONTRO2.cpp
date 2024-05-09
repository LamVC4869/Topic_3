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

int size (node head) {
    int count = 0;
    node p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void del_head (node &head) {
    if (head == NULL) return;
    node p = head;
    head = head->next;
    delete p;
}

void del (node &head, int k) {
    while (head != NULL && head->data == k) del_head (head);
    if (head == NULL) return;
    node p = head;
    while (p->next != NULL) {
        if (p->next->data == k) {
            node tmp = p->next;
            p->next = tmp->next;
            delete tmp;
        } else p = p->next;
    }
}

void print (node head) {
    node p = head;
    while (p != NULL) {
        cout << p->data << ' ';
        p = p->next;
    }
}

int main () {
    node root = NULL;
    int n, k; cin >> n >> k;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        push_back(root, make_node(x));
    }
    del (root, k);
    cout << size(root) << '\n';
    print(root);
}
