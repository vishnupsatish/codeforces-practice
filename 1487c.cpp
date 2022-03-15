#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n;
    cin >> n;

    unordered_map<int, unordered_set<int>> w;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (n - !(n & 1)) / 2; j++) {
            int aga = (i + j == n ? n : (i + j) % n);
            w[i].emplace(aga);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (i <= n / 2 && !(n & 1) && j == i + n / 2) {
                cout << 0 << ' ';
            } else if (w[i].contains(j)) {
                cout << 1 << ' ';
            } else {
                cout << -1 << ' ';
            }
        }
    }
    cout << '\n';
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
