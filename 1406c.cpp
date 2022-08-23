/**
*  author:  vishnus
*  created: 2022-08-23
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if a tree has 1 centroid, the answer is a given. A tree will have at most 2 centroids.
// Why? Because if there are 3, it is optimal to pick the middle node amongst them to be the 
// centroid since the other two will be "unbalanced" for the lack of a better term.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    pair<int, int> f;
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      f = {u, v};
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> ch(n); // Number of children of node 'i'
    function<int(int, int)> FindChildren = [&](int u, int par) {
      for (auto v : adj[u]) {
        if (v != par) {
          ch[u] += FindChildren(v, u);
        }
      }
      return ch[u] + 1;
    };
    FindChildren(0, -1);
    vector<int> cents; // all centroids
    int mxnodes = 1e9;
    function<void(int, int)> Centroids = [&](int u, int par) {
      // Remove u
      int cur_mx = 0;
      int tot = 0;
      for (auto v : adj[u]) {
        if (v != par) {
          cur_mx = max(cur_mx, ch[v] + 1);
          tot += ch[v] + 1;
        }
      }
      if (par != -1) {
        cur_mx = max(cur_mx, n - 1 - tot);
      }
      if (cur_mx == mxnodes) {
        cents.push_back(u);
      } else if (cur_mx < mxnodes) {
        cents = {u};
        mxnodes = cur_mx;
      }
      for (auto v : adj[u]) {
        if (v != par) {
          Centroids(v, u);
        }
      }
    };
    Centroids(0, -1);
    assert((int) cents.size() <= 2);
    if ((int) cents.size() == 1) {
      cout << f.first + 1 << ' ' << f.second + 1 << '\n';
      cout << f.first + 1 << ' ' << f.second + 1 << '\n';
      continue;
    }
    int val = -1;
    int pval = -1;
    int fst = cents[0];
    int sec = cents[1];
    function<void(int, int)> Dfs = [&](int u, int par) {
      if (val != -1) {
        return;
      }
      if (adj[u].size() == 1 && par != -1) {
        val = u;
        pval = par;
      }
      for (auto v : adj[u]) {
        if (v != par && v != sec) {
          Dfs(v, u);
        }
      }
    };
    Dfs(fst, -1);
    cout << pval + 1 << ' ' << val + 1 << '\n';
    cout << sec + 1 << ' ' << val + 1 << '\n';
  }
}
