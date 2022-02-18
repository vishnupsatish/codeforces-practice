#include <bits/stdc++.h>

using namespace std;

int n;


void solve() {
    cin >> n;

    vector<vector<pair<int, int>>> adj(n + 2);
    vector<int> w(n + 2);

    bool ok = true;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
        if (adj[u].size() > 2 || adj[v].size() > 2) ok = false;
    }

    if (!ok) {
        cout << -1 << '\n';
        return;
    }

    auto dfs = [adj, &w] (auto &dfs, int u, int par, int prev) -> void {
        if (prev == 0) {
            int d = -1;
            for (auto [v, ind] : adj[u]) {
                w[ind] = (d == 2 ? 3 : 2);
                dfs(dfs, v, u, d == 2 ? 3 : 2);
                d = 2;
            }
        } else {
            for (auto [v, ind] : adj[u]) {
                if (v == par) continue;
                w[ind] = (prev == 2 ? 3 : 2);
                dfs(dfs, v, u, prev == 2 ? 3 : 2);
            }
        }
    };

    dfs(dfs, 1, -1, 0);

    for (int i = 1; i < n; i++) cout << w[i] << (i == n - 1 ? '\n' : ' ');
}


int main() {
    int t; cin >> t;

    while (t--) solve();
}
