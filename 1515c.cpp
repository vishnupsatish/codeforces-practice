#include <bits/stdc++.h>

using namespace std;

// Idea: keep a set of the heights of all of the m towers (all are 0 at first).
// Then, greedily add the next shortest block to the shortest tower. An answer
// will always exist since we always add to the shortest tower, meaning that two
// towers cannot differ by >= x.

void solve() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<pair<int, int>> h(n + 2);
    vector<int> ans(n + 2);

    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        h[i] = {c, i};
    }

    set<pair<int, int>> t;

    for (int i = 1; i <= m; i++) t.emplace(0, i);

    sort(h.begin() + 1, h.begin() + n + 1);

    for (int i = 1; i <= n; i++) {
        int c = (*t.begin()).first, ind = (*t.begin()).second;

        t.erase({c, ind});
        t.emplace(c + h[i].first, ind);

        ans[h[i].second] = ind;
    }

    cout << "YES" << '\n';

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}
