#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Optimal idea is to bitwise OR only once. Why? Idk.


void solve() {
    int a, b;
    cin >> a >> b;

    int ans = 1e9;

    for (int i = a; i <= b; i++) {
        int tmp = i | b;
        ans = min(ans, (i - a) + abs(tmp - b) + 1);
    }

    for (int i = b; i <= b + (a << 1); i++) {
        int tmp = a | i;
        ans = min(ans, (i - b) + abs(tmp - i) + 1);
    }

    ans = min(ans, b - a);

    cout << ans << '\n';
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
