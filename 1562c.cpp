#include <bits/stdc++.h>

using namespace std;

// Idea: key is 0. If not, all are 1s.


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2);

    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        a[i] = c - '0';
    }

    for (int i = n; i >= n / 2 + 1; i--) {
        if (a[i] == 0) {
            cout << 1 << ' ' << i << ' ' << 1 << ' ' << i - 1 << '\n';
            return;
        }
    }

    for (int i = 1; i <= n / 2 + (n & 1); i++) {
        if (a[i] == 0) {
            cout << i << ' ' << n << ' ' << i + 1 << ' ' << n << '\n';
            return;
        }
    }

    if (n & 1) {
        cout << 2 << ' ' << n << ' ' << 2 << ' ' << n / 2 + 1 << '\n';
    } else {
        cout << 1 << ' ' << n << ' ' << 1 << ' ' << n / 2 << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}

