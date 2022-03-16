#include <bits/stdc++.h>

using namespace std;

#define ll long long

// For a colour k: there should only be one connected component with that 
// colour (greedy). When you add a colour, we want to maximize the number 
// of times a vertex with the maximum value shows up. How many times can 
// we do that? The number of children it has. Use a map for implementation.


void solve() {
    int n;
    cin >> n;

    vector<int> w(n + 2);

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        ans += w[i];
    }

    vector<vector<int>> adj(n + 2);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    map<int, int, greater<>> cnt;

    auto dfs = [&] (auto dfs, int u, int par) -> void {
        cnt[w[u]] += adj[u].size() - 1;

        for (auto v : adj[u]) {
            if (v != par) {
                dfs(dfs, v, u);
            }
        }
    };

    dfs(dfs, 1, -1);

    cout << ans << ' ';
    for (int i = 2; i < n; i++) {
        while ((*cnt.begin()).second == 0) {
            cnt.erase(cnt.begin());
        }

        ans += (ll) (*cnt.begin()).first;
        (*cnt.begin()).second--;
        cout << ans << ' ';
    }
    cout << '\n';
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
