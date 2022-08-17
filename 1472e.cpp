/**
 *    author:  vishnus
 *    created: 2022-08-17
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: sort the heights, and prefix min the widths (and do the same vice-versa). Be sure that the
// indices are being set correctly (prefix min index is the one being used). Then use binary search. Simple.

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
    vector<vector<int>> p(2 * n, vector<int>(3));
    for (int i = 0; i < n; i++) {
      cin >> p[i][0] >> p[i][1];
      p[i][2] = i;
    }
    for (int i = n; i < 2 * n; i++) {
      p[i][0] = p[i - n][1];
      p[i][1] = p[i - n][0];
      p[i][2] = i;
    }
    sort(p.begin(), p.end());
    map<int, pair<int, int>> bp;
    int prev = -1;
    int prev_idx = 0;
    for (int i = 0; i < 2 * n; i++) {
      if (i == 0) {
        bp[p[i][0]].first = p[i][1];
        prev = p[i][1];
        prev_idx = p[i][2] % n;
      } else {
        bp[p[i][0]].first = min(p[i][1], prev);
        if (p[i][1] < prev) {
          prev_idx = p[i][2] % n;
          prev = p[i][1];
        }
      }
      bp[p[i][0]].second = prev_idx;
    }
    vector<int> ans(n);
    for (int i = 0; i < 2 * n; i++) {
      if (p[i][2] >= n) {
        continue;
      }
      auto prev_one = bp.lower_bound(p[i][0]);
      if (prev_one != bp.begin()) {
        --prev_one;
      } else {
        ans[p[i][2]] = -2;
        continue;
      }
      if (bp[(*prev_one).first].first < p[i][1]) {
        ans[p[i][2]] = bp[(*prev_one).first].second;
      } else {
        ans[p[i][2]] = -2;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] + 1 << " \n"[i == n - 1];
    }
  }
}
