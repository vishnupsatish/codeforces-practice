/**
*  author:  vishnus
*  created: 2022-08-25
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: direct an edge from u -> v if 'u' must be made into 'v'. You can keep this undirected because 
// we know that if in u - v u > v then v points to u. So, we find the MST of each connected component,
// and that's the answer. Because say a -> d, and a -> b and b -> c and c -> d as well, we can first 
// make a into b (both 'a's), then b to c (both) then c to d (both) and we made the a -> d work out 
// by following the smaller paths.

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
    string a, b;
    cin >> a >> b;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    vector<unordered_set<char>> adj(26);
    set<tuple<int, int, int>, greater<>> edges;
    for (int i = 0; i < n; i++) {
      edges.insert({(b[i] - 'a') - (a[i] - 'a'), a[i] - 'a', b[i] - 'a'});
    }
    vector<int> dsu(26);
    for (int i = 0; i < 26; i++) {
      dsu[i] = i;
    }
    function<int(int)> Find = [&](int e) {
      if (dsu[e] != e) {
        dsu[e] = Find(dsu[e]);
      }
      return dsu[e];
    };
    int ans = 0;
    for (auto [wt, u, v] : edges) {
      if (Find(u) != Find(v)) {
        dsu[Find(u)] = Find(v);
        ans++;
      }
    }
    cout << ans << '\n';
  }
}
