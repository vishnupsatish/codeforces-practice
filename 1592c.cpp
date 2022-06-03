/**
 *    author:  vishnus
 *    created: 2022-06-03
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: few key observations to make here. First, any tree that is split into m
// components can be split into m - 2 components, since three adjacent components
// (which all have the same xor value) can be combined into one component since
// x ^ x ^ x = x. Also, if the xor of the entire tree is 0, then we can split the
// tree into two components since we know that x ^ x = 0 and we can take any
// subtree and make that one of our components. Otherwise, we need to split the
// tree into three components, with the xor of each component being equal to the
// xor of the entire tree. This is because presumably there are three components
// with the same xor, and x ^ x ^ x = x. To find if such three components exist,
// we can run a DFS to find the deepest subtree such that its xor == the entire
// tree's xor, then remove that subtree, then run the same DFS again. If both
// DFSs return a valid subtree, then it is possible. Why does this work? Because 
// there is guaranteed to be a subtree (that does not include the root) that has
// the valid xor value. By taking the deepest one, we ensure that we do not take
// any subtrees that has a subtree inside of it that also has a valid value.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &e : a) {
      cin >> e;
    }
    vector<unordered_set<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      adj[u].insert(v);
      adj[v].insert(u);
    }
    int xval = 0;
    function<void(int, int)> Dfs1 = [&](int u, int par) -> void {
      xval ^= a[u];
      for (auto v : adj[u]) {
        if (v != par) {
          Dfs1(v, u);
        }
      }
    };
    Dfs1(0, -1);
    if (xval == 0) { // Since a ^ a = 0 for all a, we need to split this tree into two components, and it is possible
      cout << "YES" << '\n';
      continue;
    } else if (k >= 3) { // If it is not 0, we need to split it into three components and k must be >= 3
      // Find the deepest subtree such that its xor == the entire tree's xor, remove that edge, then do it again
      map<int, pair<int, int>, greater<>> rm;
      function<int(int, int, int)> Dfs2 = [&](int u, int par, int lvl) -> int {
        int x = a[u];
        for (auto v : adj[u]) {
          if (v != par) {
            x ^= Dfs2(v, u, lvl + 1);
          }
        }
        if (x == xval && par != -1) {
          rm[lvl] = {u, par};
        }
        return x;
      };
      Dfs2(0, -1, 0);
      if (rm.empty()) {
        cout << "NO" << '\n';
        continue;
      }
      pair<int, int> uv = (*rm.begin()).second;
      adj[uv.first].erase(uv.second);
      adj[uv.second].erase(uv.first);
      rm.clear();
      Dfs2(0, -1, 0);
      if (rm.empty()) {
        cout << "NO" << '\n';
        continue;
      }
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
