/**
 *    author:  vishnus
 *    created: 2022-06-06
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: we have 2m queries. For the first m queries, find the weight of each
// edge. Then, consider a Kruskal-like algorithm. Sort each edge, then iterate.
// Query all edges that formed a MSF and the current edge. If the value is not
// equal to the previous value plus the current edge, that means a lesser edge
// was removed and this forest is not optimal, since a greater edge was put in
// place of the lesser edge, so don't include it in the value. Finally, output
// the value.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  auto Ask = [&](const unordered_set<int>& to) {
    vector<int> s(m);
    for (auto e : to) {
      s[e] = 1;
    }
    cout << "? ";
    for (auto e : s) {
      cout << e;
    }
    cout << endl;
    int val;
    cin >> val;
    return val;
  };
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    edges[i] = {Ask({i}), i};
  }
  sort(edges.begin(), edges.end());
  long long val = 0;
  unordered_set<int> asf;
  for (auto [w, idx] : edges) {
    val += w;
    asf.insert(idx);
    if (Ask(asf) != val) {
      val -= w;
      asf.erase(idx);
    }
  }
  cout << "! " << val << endl;
}
