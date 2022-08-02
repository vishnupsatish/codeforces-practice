/**
 *    author:  vishnus
 *    created: 2022-08-02
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: binary search the prefix sums of 'b' on the current path. Use a stack.

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
    vector<int> a(n), b(n);
    for (int i = 1; i < n; i++) {
      int p;
      cin >> p >> a[i] >> b[i];
      --p;
      adj[p].push_back(i);
    }
    vector<long long> prefa(n), prefb(n); // Prefix sum the a and b values
    function<void(int, int)> PrefDfs = [&](int u, int par) {
      if (par != -1) {
        prefa[u] = prefa[par] + a[u];
        prefb[u] = prefb[par] + b[u];
      }
      for (auto v : adj[u]) {
        PrefDfs(v, u);
      }
    };
    PrefDfs(0, -1);
    vector<long long> stk; // Stack for DFS - what is the path from 1 to 'i'?
    vector<int> r(n);
    function<void(int, int)> Dfs = [&](int u, int par) {
      stk.push_back(prefb[u]);
      if (par != -1) {
        r[u] = (int) (upper_bound(stk.begin(), stk.end(), prefa[u]) - stk.begin() - 1);
      }
      for (auto v : adj[u]) {
        Dfs(v, u);
      }
      stk.pop_back();
    };
    Dfs(0, -1);
    for (int i = 1; i < n; i++) {
      cout << r[i] << " \n"[i == n - 1];
    }
  }
}
