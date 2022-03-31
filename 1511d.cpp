/**
 *    author:  vishnus
 *    created: 2022-03-31
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: each substring ab, ac, ad -> kk (where k is the value k, not the letter k)
// increases the answer by cnt * (cnt - 1) / 2. We want to find the longest string
// such that each substring of length 2 appears once (i.e. answer is 0). We can find
// the Eulerian cycle of the graph where a <-> b for each character until k. Since
// it is the Eulerian cycle, it starts and ends at the same node. Therefore, when
// the cycle it if n > k^2, we just repeat the characters except the first one. This
// is because it is optimal to bring all cnt[a] for a from a -> value of k as close as
// as possible (and including the first character will have an extra aa for all expansions
// of the string).

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> adj(k, vector<int>(k));
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      adj[i][j] = 1;
    }
  }
  vector<char> ans;
  function<void(int)> Eulerian = [&](int u) {
    for (int v = 0; v < k; v++) {
      if (adj[u][v] == 1) {
        adj[u][v] = 0;
        Eulerian(v);
      }
    }
    ans.push_back((char) u + 'a');
  };
  Eulerian(0);
  cout << ans[0];
  ans.erase(ans.begin());
  for (int i = 0; i < n - 1; i++) {
    cout << ans[i % (int) ans.size()];
  }
  cout << '\n';
}
