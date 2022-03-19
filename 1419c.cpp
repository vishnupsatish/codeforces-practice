#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Answer is always either 0 (all are x), 1 (there is >= one
// that is x or the average is equal to x), 2 (all other cases).


void solve() {
    int n, x;
    cin >> n >> x;

    int s = 0;

    bool one = true, is_there = false;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        s += a;
        if (a != x) {
            one = false;
        } else {
            is_there = true;
        }
    }

    if (one) {
        cout << 0 << '\n';
    } else if (is_there || (s % n == 0 && s / n == x)) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}
