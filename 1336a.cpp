/**
 *    author:  vishnus
 *    created: 2022-05-10
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if a node must be selected, all of its children must be selected as tourist 
// cities first. So, we can calculate the gain/loss of choosing each node assuming 
// its children have already been selected. A node's gain value = the level - number 
// of nodes below it. Why? For the node itself, we can travel through 'level' nodes 
// above it to the root, which will all be industry cities. But, for each node below 
// it, the number of industry nodes a node can travel reduces by one (since one of 
// its ancestors now becomes a tourism node). Then, we use simple sorting.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> val(n);
  function<int(int, int, int)> Dfs = [&](int u, int par, int l) -> int {
    int cnt = 0; // Number of nodes below the current node
    for (auto v : adj[u]) {
      if (v != par) {
        cnt += Dfs(v, u, l + 1) + 1;
      }
    }
    val[u] = l - cnt;
    return cnt;
  };
  Dfs(0, -1, 0);
  sort(val.begin(), val.end(), greater<>());
  cout << accumulate(val.begin(), val.begin() + k, 0ll) << '\n';
}
