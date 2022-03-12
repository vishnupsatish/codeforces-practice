#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: either three or two elements remaining.


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2), p(n + 2);

    int x = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        x ^= a[i];
        p[i] = p[i - 1] ^ a[i];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = i; j < n; j++) { // Middle section: i to j inclusive
            if (p[i - 1] == (p[j] ^ p[i - 1]) && p[i - 1] == (p[n] ^ p[j])) {
                cout << "YES" << '\n';
                return;
            }
        }
    }

    if (x == 0) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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

