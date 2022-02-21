#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n; cin >> n;

    set<pair<int, int>, greater<>> a;

    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        if (c != 0) a.emplace(c, i);
    }

    vector<pair<int, int>> ans;

    while (a.size() > 1) {
        int c1 = (*a.begin()).first, c2 = (*(++a.begin())).first;
        int i = (*a.begin()).second, j = (*(++a.begin())).second;

        ans.emplace_back(i, j);

        a.erase({c1, i});
        a.erase({c2, j});
        if (c1 != 1) a.emplace(c1 - 1, i);
        if (c2 != 1) a.emplace(c2 - 1, j);
    }

    cout << ans.size() << '\n';

    for (auto [i, j] : ans) cout << i << ' ' << j << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}
