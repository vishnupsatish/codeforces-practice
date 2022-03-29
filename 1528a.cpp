/**
 *    author:  vishnus
 *    created: 2022-03-28
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: tree DP: d[i][l_or_r] indicates the best value for the ith node if l or r was chosen. dp[i][l_or_r] += each value for its subtrees. (Take max of those).

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<vector<long long>> dp(n, vector<long long>(2, -1));
    function<long long(int, int, bool)> Dfs = [&](int u, int par, bool wo) { // wo 1: choose right, 0: choose left
      if (dp[u][wo] != -1) {
        return dp[u][wo];
      }
      long long cur = 0;
      if (wo) {
        for (auto v : adj[u]) {
          if (v != par) {
            cur += max(Dfs(v, u, 1) + abs(r[u] - r[v]), Dfs(v, u, 0) + abs(r[u] - l[v]));
          }
        }
      } else {
        for (auto v : adj[u]) {
          if (v != par) {
            cur += max(Dfs(v, u, 1) + abs(l[u] - r[v]), Dfs(v, u, 0) + abs(l[u] - l[v]));
          }
        }
      }
      return dp[u][wo] = cur;
    };
    cout << max(Dfs(1, -1, 0), Dfs(1, -1, 1)) << '\n';
  }
}
