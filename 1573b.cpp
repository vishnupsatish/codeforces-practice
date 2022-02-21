#include <bits/stdc++.h>

using namespace std;

// Minimize i + j such that ai < bj. idx[x] represents the smallest index such that b[idx[x]] >= x. Precompute that.

void solve() {
    int n; cin >> n;

    vector<int> a(n + 2), b(n + 2), idx(2 * n + 2);

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
        if (idx[b[i]]) continue;

        for (int j = b[i]; j >= 2; j -= 2) {
            if (idx[j]) break;
            idx[j] = i;
        }
    }

    int ans = 1e9;

    for (int i = 1; i <= n; i++) {
        ans = min(ans, i + idx[a[i] + 1]);
    }

    cout << ans - 2 << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}
