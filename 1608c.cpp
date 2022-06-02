/**
 *    author:  vishnus
 *    created: 2022-06-02
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: add an edge from u -> v if player u can beat player v. This would lead to n^2 edges, so we can
// reduce this by sorting 'a' and 'b' and adding an edge between adjacent elements. Player u wins if you
// can do from u -> v for every possible v. The complexity of this would be O(N^2). Instead of doing this,
// we can realize a player u will win only if it can reach the node with the maximum a[i] value. Why is
// this? because if it can't reach that node, then it can't win (by definition). But, if it can reach that
// node, then we know that since it has the maximum a[i] value, it can beat every other node. Therefore,
// we can reverse each edge and start at node with the highest a[i] value. All nodes reachable from that
// node can win.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i].first;
      b[i].second = i;
    }
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
      adj[a[i].second].push_back(a[i - 1].second);
      adj[b[i].second].push_back(b[i - 1].second);
    }
    vector<int> w(n);
    vector<int> vis(n);
    function<void(int)> Dfs = [&](int u) {
      w[u] = 1;
      for (auto v : adj[u]) {
        if (!vis[v]) {
          vis[v] = 1;
          Dfs(v);
        }
      }
    };
    vis[a[0].second] = 1;
    Dfs(a[0].second);
    for (auto e : w) {
      cout << e;
    }
    cout << '\n';
  }
}
