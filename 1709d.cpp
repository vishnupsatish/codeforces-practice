/**
 *    author:  vishnus
 *    created: 2022-08-01
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: go as high as needed to go above the highest blocked cell in a range, then just check for mod k.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (auto &e : a) {
    cin >> e;
  }
  int ht = (int) log2(m);
  vector<vector<int>> st(m, vector<int>(ht + 1));
  // Build sparse table
  for (int i = 0; i < m; i++) {
    st[i][0] = a[i];
  }
  for (int j = 1; j <= ht; j++) {
    for (int i = 0; i + (1 << j) <= m; i++) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
  // Query spare table
  auto RangeMax = [&](int l, int r) {
    if (r < l) {
      swap(l, r);
    }
    int ans = 0;
    for (int j = ht; j >= 0; j--) {
      if ((1 << j) <= r - l + 1) {
        ans = max(ans, st[l][j]);
        l += 1 << j;
      }
    }
    return ans;
  };
  int q;
  cin >> q;
  while (q--) {
    int r, c, rf, cf, k;
    cin >> r >> c >> rf >> cf >> k;
    --r; --c; --rf; --cf;
    if (r == rf && c == cf) {
      cout << "YES" << '\n';
      continue;
    }
    if (abs(cf - c) % k != 0) {
      cout << "NO" << '\n';
      continue;
    }
    int mx = max(rf, max(r, RangeMax(c, cf))); // Have to start at y and go above or at 'mx'; is it possible?
    if (mx == n) {
      cout << "NO" << '\n';
      continue;
    }
    int mx_row = r + k * (int) ceil((double) (mx - r) / (double) k);
    if (mx_row >= n) {
      cout << "NO" << '\n';
      continue;
    }
    if (abs(mx_row - rf) % k != 0) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
  }
}
