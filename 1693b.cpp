/**
 *    author:  vishnus
 *    created: 2022-06-29
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: we know that the most optimal thing to do is to use the minimum number of operations for a
// subtree, and nothing more. If we were to use more, we could just transfer those operations to the
// parent (or an ascendant). There are a few conditions. First, every leaf node should get an operation.
// Next, operations can be passed upwards from descendents to the current node. There are some 
// conditions for this. Say the maximum number that can be passed upwards from node u is mx[u]. An
// operation must be performed on node u (ans++) if the sum of mx of its children is less than l[u].
// Then, we set mx[u] = r[u] which is the greedily best thing to do. Otherwise, we set mx[u] = 
// min(sum of mx of its children, r[u]) since the childrens' operations at the current node will be
// reduced to have a maximum sum of r[u] so it doesn't exceed r[u]. We only need to consider mx values
// of a node's children, not all of its descendants because the operation values are restricted by 
// the childrens' values. If not restricted, they keep adding up in a DP fashion.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
      int par;
      cin >> par;
      --par;
      adj[par].push_back(i);
      adj[i].push_back(par);
    }
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
    }
    int ans = 0;
    vector<int> mx(n);
    function<void(int, int)> Dfs = [&](int u, int par) -> void {
      if (par != -1 && (int) adj[u].size() == 1) { // Leaf
        ans++;
        mx[u] = r[u];
        return;
      }
      long long mx_sum = 0;
      for (auto v : adj[u]) {
        if (v != par) {
          Dfs(v, u);
          mx_sum += mx[v];
        }
      }
      if (mx_sum < l[u]) {
        ans++;
        mx[u] = r[u];
      } else {
        mx[u] = min((long long) r[u], mx_sum);
      }
    };
    Dfs(0, -1);
    cout << ans << '\n';
  }
}
