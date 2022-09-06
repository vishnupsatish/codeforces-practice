/**
*  author:  vishnus
*  created: 2022-09-06
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: root the tree at 'x' and go to all nodes that have a node to visit in their subtree. Count these nodes 
// twice UNLESS 'y' is in their subtree in which case we finish it off at 'y' and don't need to go back up.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    int x, y;
    cin >> x >> y;
    --x; --y;
    vector<int> a(k);
    vector<int> isa(n);
    for (auto &e : a) {
      cin >> e;
      --e;
      isa[e]++;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> dist(n);
    function<void(int, int, int)> DistDfs = [&](int u, int par, int cd) {
      dist[u] = cd;
      for (auto v : adj[u]) {
        if (v != par) {
          DistDfs(v, u, cd + 1);
        }
      }
    };
    DistDfs(x, -1, 0);
    vector<int> vs(n); // How many houses we need to go to are in i's subtree?
    vector<int> hy(n); // Does subtree 'i' contain 'y'?
    function<int(int, int)> VFind = [&](int u, int par) {
      for (auto v : adj[u]) {
        if (v != par) {
          vs[u] += VFind(v, u);
        }
      }
      vs[u] += isa[u];
      return vs[u];
    };
    VFind(x, -1);
    function<int(int, int)> HasYFind = [&](int u, int par) {
      for (auto v : adj[u]) {
        if (v != par) {
          hy[u] = max(hy[u], HasYFind(v, u));
        }
      }
      hy[u] = max(hy[u], (int) (u == y));
      return hy[u];
    };
    HasYFind(x, -1);
    int ans = 0;
    function<void(int, int)> Dfs = [&](int u, int par) {
      if (!vs[u] && !hy[u]) {
        return;
      }
      ans += (int) (u != x) + !hy[u];
      for (auto v : adj[u]) {
        if (v != par) {
          Dfs(v, u);
        }
      }
    };
    Dfs(x, -1);
    cout << ans << '\n';
  }
}
