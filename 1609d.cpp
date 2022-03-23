/**
 *    author:  vishnus
 *    created: 2022-03-23
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: use DSU to unite new friends. We have += 1 leeway for every pair of friends
// that connect that are already friends. For each leeway, we greedily combine the
// largest groups and make one person inside friends with all the others.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<int> dsu(n);
  for (int i = 0; i < n; i++) {
    dsu[i] = i;
  }
  function<int(int)> Find = [&](int e) {
    if (e != dsu[e]) {
      dsu[e] = Find(dsu[e]);
    }
    return dsu[e];
  };
  int dn = 1;
  for (int i = 0; i < d; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    dn += (Find(x) == Find(y));
    dsu[Find(x)] = Find(y);
    unordered_map<int, int> cnt;
    for (int j = 0; j < n; j++) {
      cnt[Find(j)]++;
    }
    multiset<int, greater<>> val;
    for (auto [k, v] : cnt) {
      val.emplace(v);
    }
    int ccnt = 0;
    int ans = 0;
    for (auto v : val) {
      ccnt++;
      if (ccnt > dn) {
        break;
      }
      ans += v;
    }
    cout << ans - 1 << '\n';
  }
  return 0;
}
