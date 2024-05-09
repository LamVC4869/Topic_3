#include <iostream>

using namespace std;

void solve (int *p, int n) {
    bool dx = true, out = false;
    int k = (n & 1) ? (n - 1)/2 : n/2;
    for (int i = 0; i < k; i++) {
        if (p[i] != p[n - i - 1]) {
            dx = false;
            if (!out) {
                cout << "mang khong doi xung\n";
                out = true;
            }
            cout << p[i] << ' ' << p[n - i - 1] << '\n';
        }
    }
    if (dx) cout << "mang doi xung";
}

int main () {
    int n; cin >> n;
    int *p = new int [n];
    for (int i = 0; i < n; i++) cin >> p[i];
    solve (p, n);
}
