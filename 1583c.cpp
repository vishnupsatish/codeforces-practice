/**
 *    author:  vishnus
 *    created: 2022-06-03
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if a grid has a cell such that its top and left cells are filled, then we cannot
// determine whether or not it is filled or not since it is not exitable, but it could be
// filled or not filled since it will not be exitable regardless. We can use a PSA to
// determine this. Why does this work? If there are no such cells, it implies that all
// exitable cells are empty and all non-exitable cells are filled, which satisfies the
// criteria.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m)); // 1 if filled, 0 if not filled
  for (auto &r : a) {
    for (auto &e : r) {
      char x;
      cin >> x;
      e = (x == 'X');
    }
  }
  vector<int> colpref(m + 1);
  for (int j = 1; j < m; j++) {
    colpref[j + 1] = colpref[j];
    for (int i = 1; i < n; i++) {
      if (a[i][j - 1] == 1 && a[i - 1][j] == 1) {
        colpref[j + 1]++;
        break;
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int x1, x2;
    cin >> x1 >> x2;
    --x1; --x2;
    cout << (colpref[x2 + 1] - colpref[x1 + 1] == 0 ? "YES" : "NO") << '\n';
  }
}
