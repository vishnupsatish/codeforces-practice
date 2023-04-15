#include <bits/stdc++.h>

using namespace std;

// Editorial was used

// Idea: https://imgur.com/a/mvo1tcq

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  vector<int> bck(n, -1);
  for (int i = 1; i < n; i++) {
    cin >> bck[i];
    --bck[i];
    adj[bck[i]].push_back(i);
  }
  vector<int> dp(n);
  vector<int> dist(n); // (max) distance from ground
  function<void(int)> Dfs = [&](int u) {
    int val = 0;
    for (auto v : adj[u]) {
      Dfs(v);
      val += dp[v];
      dist[u] = max(dist[u], dist[v] + 1);
    }
    if (adj[u].empty()) {
      dist[u] = dp[u] = 1;
      return;
    }
    dp[u] = max(val, dist[u]);
  };
  Dfs(0);
  cout << dp[0] << '\n';
}
