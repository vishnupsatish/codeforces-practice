/**
 *    author:  vishnus
 *    created: 2022-04-21
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: inject every child once, then based on the time we injected
// (be greedy based on the number of siblings), some nodes may be spread
// to within that time. For the rest of the nodes, we can take the
// one with the most siblings, inject those (everything else will go down
// by one, that will go down by two), then use a set to simulate the process.
// Why inject the one with the most siblings in the second step? Because
// if we injected a one with less than the most siblings, in one step
// we might inject into something, but we won't be able to spread it since
// there are no more nodes, making one less node get the disease than if
// we injected the one with the most siblings.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> par(n);
    for (int i = 1; i < n; i++) {
      int u;
      cin >> u;
      --u;
      par[i] = u;
      adj[u].push_back(i);
    }
    vector<int> inj_ord;
    vector<int> inj(n, -1);
    function<void(int, int)> Dfs1 = [&](int u, int par) {
      if (!adj[u].empty()) { // If node has >= 1 child, inject one child of that node
        inj_ord.push_back(adj[u][0]);
      }
      for (auto v : adj[u]) {
        if (v != par) {
          Dfs1(v, u);
        }
      }
    };
    Dfs1(0, -1);
    sort(inj_ord.begin(), inj_ord.end(), [&] (int v1, int v2) { return adj[par[v1]].size() > adj[par[v2]].size(); });
    inj_ord.push_back(0);
    int tot_inj = (int) inj_ord.size();
    for (int i = 0; i < (int) inj_ord.size(); i++) {
      inj[inj_ord[i]] = i + 1;
    }
    multiset<int, greater<>> trm;
    function<void(int, int)> Dfs2 = [&](int u, int par) {
      if (!adj[u].empty()) {
        int rem = (int) adj[u].size() - 1 - (tot_inj - inj[adj[u][0]]);
        if (rem > 0) {
          trm.insert(rem);
        }
      }
      for (auto v : adj[u]) {
        if (v != par) {
          Dfs2(v, u);
        }
      }
    };
    Dfs2(0, -1);
    int cnt = 0;
    int all_red = 0;
    while (!trm.empty()) {
      int cur = *trm.begin();
      trm.erase(trm.find(cur));
      if (cur - all_red > 0) {
        cur--;
        if (cur - all_red > 0) {
          trm.insert(cur);
        }
        all_red++;
        cnt++;
      }
    }
    cout << tot_inj + cnt << '\n';
  }
}
