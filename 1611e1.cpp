/**
 *    author:  vishnus
 *    created: 2022-06-01
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Simple algorithm. Run a multi-source BFS to determine the minimum distance from a friend to 
// node 'i' (array 'dist'). Imagine we want to go to some leaf node. For all nodes on the path from 
// node 0 to that leaf, the distance from node 0 to that leaf (amount of it time it takes Vlad to get
// there) must be less than the distance from the closest friend to that node. Otherwise, it will get
// intercepted by that friend on the way there. If there is at least one leaf such that this is 
// satisfied, then the answer is YES, otherwise Vlad will get intercepted no matter where he goes, 
// so the answer is NO.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> x(n); // 1 if room 'i' has a friend
    for (int i = 0; i < k; i++) {
      int cur;
      cin >> cur;
      --cur;
      x[cur] = 1;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> dist(n, -1); // Minimum distance from any friend to the node 'i'
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (x[i]) {
        q.push(i);
        dist[i] = 0;
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : adj[u]) {
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    bool win = false;
    function<void(int, int, int)> Dfs = [&](int u, int par, int lvl) -> void {
      if (lvl >= dist[u]) {
        return;
      }
      if (par != -1 && (int) adj[u].size() == 1) {
        win = true;
        return;
      }
      for (auto v : adj[u]) {
        if (v != par) {
          Dfs(v, u, lvl + 1);
        }
      }
    };
    Dfs(0, -1, 0);
    cout << (win ? "YES" : "NO") << '\n';
  }
}
