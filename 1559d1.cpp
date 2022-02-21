#include <bits/stdc++.h>

using namespace std;

// Idea: we can add an edge between nodes if they are in different
// components. Add edge, then make them the same component.

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<int> dsu1(n + 2), dsu2(n + 2);

    for (int i = 1; i <= n; i++) dsu1[i] = dsu2[i] = i;

    auto find = [] (auto &find, int e, vector<int> &dsu) -> int {
        if (dsu[e] != e) dsu[e] = find(find, dsu[e], dsu);
        return dsu[e];
    };

    for (int i = 1; i <= m1; i++) {
        int u, v; cin >> u >> v;

        dsu1[find(find, u, dsu1)] = find(find, v, dsu1);
    }

    for (int i = 1; i <= m2; i++) {
        int u, v; cin >> u >> v;

        dsu2[find(find, u, dsu2)] = find(find, v, dsu2);
    }

    vector<pair<int, int>> ans;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (find(find, i, dsu2) != find(find, j, dsu2) && find(find, i, dsu1) != find(find, j, dsu1)) {
                ans.emplace_back(i, j);
                dsu1[find(find, i, dsu1)] = find(find, j, dsu1);
                dsu2[find(find, i, dsu2)] = find(find, j, dsu2);
            }
        }
    }

    cout << ans.size() << '\n';

    for (auto [u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
}
