#include <bits/stdc++.h>

using namespace std;

#define int long long

// Idea: both xor and sum have the same parities. odd ^/+ even = odd, odd ^/+ odd = even,
// even ^/+ even = even. Just try and determine the parity for one of them, either that
// or the other must work.

void solve() {
    int n, x, y; cin >> n >> x >> y;

    int s = 0;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        s += a;
    }

    if (((s + x) & 1) == (y & 1)) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
}


signed main() {
    int t; cin >> t;

    while (t--) solve();
}
