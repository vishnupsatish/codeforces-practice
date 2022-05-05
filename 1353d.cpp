/**
 *    author:  vishnus
 *    created: 2022-05-05
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: set bash

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, set<int>, greater<>> seg;
    seg[n].insert(0);
    for (int i = 0; i < n; i++) {
      int sz = (*seg.begin()).first;
      int idx = *((*seg.begin()).second.begin());
      int l = idx, r = idx + sz - 1;
      int mid = (l + r) / 2;
      a[mid] = i + 1;
      seg[sz].erase(idx);
      if (seg[sz].empty()) {
        seg.erase(sz);
      }
      if (sz == 2) {
        seg[1].insert(r);
      } else if (sz > 2) {
        if (sz & 1) {
          seg[sz / 2].insert(l);
          seg[sz / 2].insert(mid + 1);
        } else {
          seg[sz / 2 - 1].insert(l);
          seg[sz / 2].insert(mid + 1);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
}
