/**
 *    author:  vishnus
 *    created: 2022-03-24
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: start the main DFS at the node which is the radius of the tree,
// and greedily remove nodes based on their adjacent nodes' removal values.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    if (n == 2) {
      cout << 0 << '\n';
      continue;
    }
    vector<int> dist1(n);
    function<void(int, int)> Dfs1 = [&](int u, int par) {
      for (auto v : adj[u]) {
        if (v != par) {
          dist1[v] = dist1[u] + 1;
          Dfs1(v, u);
        }
      }
    };
    Dfs1(1, -1);
    int frth, dst = 0;
    for (int i = 0; i < n; i++) {
      if (dist1[i] > dst) {
        frth = i;
        dst = dist1[i];
      }
    }
    vector<int> dist2(n), pth(n, -1);
    function<void(int, int)> Dfs2 = [&](int u, int par) {
      for (auto v : adj[u]) {
        if (v != par) {
          dist2[v] = dist2[u] + 1;
          pth[v] = u;
          Dfs2(v, u);
        }
      }
    };
    Dfs2(frth, -1);
    int frth2, dst2 = 0;
    for (int i = 0; i < n; i++) {
      if (dist2[i] > dst2) {
        frth2 = i;
        dst2 = dist2[i];
      }
    }
    vector<int> path;
    int cur = frth2;
    while (cur != -1) {
      path.push_back(cur);
      cur = pth[cur];
    }
    int mid = path[(int) path.size() / 2];
    int rmcnt = 0;
    function<int(int, int)> Dfs = [&](int u, int par) {
      if ((int) adj[u].size() == 1 && par != -1) {
        rmcnt++;
        return 1;
      }
      vector<int> vls;
      for (auto v : adj[u]) {
        if (v != par) {
          vls.push_back(Dfs(v, u));
        }
      }
      sort(vls.begin(), vls.end(), greater<>());
      int val;
      if (par != -1) {
        val = vls[0];
      } else {
        val = vls[1];
      }
      val++;
      rmcnt += (val <= k);
      return val;
    };
    Dfs(mid, -1);
    cout << n - rmcnt << '\n';
  }
}
