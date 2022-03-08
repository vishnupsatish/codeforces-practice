#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n, k;
    cin >> n >> k;

    if (n == 4 && k == 3) {
        cout << -1 << '\n';
        return;
    }
    
    if (k == n - 1) {
        cout << k << ' ' << k - 1 << '\n';
        cout << 1 << ' ' << k - 2 << '\n';
        cout << 2 << ' ' << 0 << '\n';
        for (int i = 3; i <= n / 2 - 1; i++) {
            cout << i << ' ' << n - i - 1 << '\n';
        }
    } else {
        cout << n - 1 << ' ' << k << '\n';
        if (n - k - 1 != n - 1 && 0 != n - 1) {
            cout << n - k - 1 << ' ' << 0 << '\n';
        }
        for (int i = n - 2; i >= n / 2; i--) {
            if (i != k && i != n - k - 1) {
                cout << i << ' ' << n - i - 1 << '\n';
            }
        }
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

