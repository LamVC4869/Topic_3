#include <iostream>

using namespace std;

bool isPrime (int n) {
    for (int i = 2; i*i <= n; i++) if (n % i == 0) return false;
    return n > 1;
}

void push (int* &p, int &size, int k) {
    int *tmp = new int[size + 1];
    for (int i = 0; i < size; i++) tmp[i] = p[i];
    tmp[size] = k;
    delete []p;
    p = tmp;
    size++;
}

int main () {
    int n, m; cin >> n >> m;
    int size = 0;
    int *p = new int;
    for (int i = n; i <= m; i++) if (isPrime(i)) push(p, size, i);
    for (int i = 0; i < size; i++) cout << p[i] << ' ';
}
