/**
*  author:  vishnus
*  created: 2022-08-29
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: first check if the answer is -1: this is case when a node does not fulfil the criteria 
// that its topic must be the minimum possible such that its neighbours do not have that topic.
// If that criteria is fulfilled, then just greedily choose topic for the minimum possible topic first.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> t(n);
  for (auto &e : t) {
    cin >> e;
  }
  vector<int> vis1(n);
  bool ok = true;
  function<void(int)> Check = [&](int u) {
    set<int> vals;
    for (int i = 1; i <= (int) adj[u].size() + 1; i++) {
      vals.insert(i);
    }
    for (auto v : adj[u]) {
      if (vals.contains(t[v])) {
        vals.erase(t[v]);
      }
    }
    if (t[u] != *vals.begin()) {
      ok = false;
      return;
    }
    for (auto v : adj[u]) {
      if (!vis1[v]) {
        vis1[v] = 1;
        Check(v);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    if (!vis1[i]) {
      Check(i);
    }
  }
  if (!ok) {
    cout << -1 << '\n';
    return 0;
  }
  vector<pair<int, int>> it(n);
  for (int i = 0; i < n; i++) {
    it[i] = {t[i], i};
  }
  sort(it.begin(), it.end());
  for (int i = 0; i < n; i++) {
    cout << it[i].second + 1 << " \n"[i == n - 1];
  }
}
