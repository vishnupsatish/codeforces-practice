#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int x;
    cin >> x;

    while (x >= 0) {
        if (x % 11 == 0) {
            cout << "YES" << '\n';
            return;
        }
        x -= 111;
    }

    cout << "NO" << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}
