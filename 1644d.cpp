#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MOD = 998244353;

// what the hell is wrong with me putting hyphens in the mod

// Find the number of possibly-different-coloured cells and the answer
// will be k^that number. How to find? Iterate backwards since any first
// queries can be overwritten by next queries. If such a row and column
// doesn't exist and all rows and all columns have not been coloured,
// then that query has at least one cell that can be that colour.


void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    unordered_set<int> r, c;

    vector<pair<int, int>> xy(q + 2);

    for (int i = 1; i <= q; i++) {
        int x, y; cin >> x >> y;
        xy[i] = {x, y};
    }

    ll ans = 1;

    for (int i = q; i >= 1; i--) {
        if (r.size() == n || c.size() == m) {
            break;
        }

        if (!(r.contains(xy[i].first) && c.contains(xy[i].second))) {
            ans *= (ll) k;
            ans %= MOD;
        }

        r.emplace(xy[i].first);
        c.emplace(xy[i].second);
    }

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
