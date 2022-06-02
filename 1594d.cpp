/**
 *    author:  vishnus
 *    created: 2022-06-02
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: we can create an undirected graph. If u calls v an imposter, we know that they will be on 
// different teams. If u calls v a crewmate, then they will be on the same team. Therefore, we can
// add a edge u -> v and specify whether they're on different teams or not. Then, for each component,
// we run a DFS, making the starting node arbitrarily an imposter. We then determine if the graph 
// is bipartite, and determine the number of imposters in that component. We then add to the answer
// the maximum of the number of imposters and crewmates, since we can make all crewmates imposters 
// simply by making the starting node a crewmate.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> msg; // 1: crewmate, 0: imposter
    bool ok = true;
    for (int i = 0; i < m; i++) {
      int u, v;
      string s;
      cin >> u >> v >> s;
      --u; --v;
      int cr = s == "crewmate" ? 1 : 0;
      if (msg.contains({u, v}) && msg[{u, v}] != cr) {
        ok = false;
      }
      msg[{u, v}] = cr;
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    vector<vector<pair<int, int>>> adj(n);
    for (auto [k, cr] : msg) {
      auto [u, v] = k;
      adj[u].push_back({v, cr});
      adj[v].push_back({u, cr});
    }
    vector<int> vis(n);
    vector<int> val(n);
    int part_cnt = 0;
    function<int(int, int)> Dfs = [&](int u, int cr) -> int { // Returns number of imposters
      part_cnt++;
      int imp_cnt = 0;
      for (auto [v, edge_cr] : adj[u]) {
        int ncr;
        if (cr == 1) {
          ncr = edge_cr;
        } else {
          ncr = !edge_cr;
        }
        if (val[v] != ncr && vis[v]) {
          ok = false;
          return -1;
        }
        if (!vis[v]) {
          vis[v] = 1;
          val[v] = ncr;
          imp_cnt += Dfs(v, ncr);
        }
      }
      return imp_cnt + !cr;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (vis[i]) {
        continue;
      }
      vis[i] = 1;
      int cur_imp = Dfs(i, 0);
      ans += max(part_cnt - cur_imp, cur_imp);
      part_cnt = 0;
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans << '\n';
  }
}
