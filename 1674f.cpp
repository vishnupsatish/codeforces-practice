/**
*  author:  vishnus
*  created: 2022-09-06
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: answer changes by at most 1, find how much it changes by using simple math and casework.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> a(n, vector<int>(m));
  int icons = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char val;
      cin >> val;
      a[i][j] = val == '*';
      icons += a[i][j];
    }
  }
  int curcnt = 0;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      curcnt++;
      if (curcnt > icons) {
        break;
      }
      if (a[j][i] == 0) {
        ans++;
      }
    }
    if (curcnt == icons) {
      break;
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    if (a[x][y] == 1) { // we remove
      if (a[((icons - 1) % n)][(icons - 1) / n] == 1 && ((icons - 1) / n != y || ((icons - 1) % n) != x)) {
        ans++;
      }
      if (y < (icons) / n || (y == (icons) / n && x < ((icons) % n))) {

      } else {
        ans--;
      }
      icons--;
    } else {
      icons++;
      if (a[((icons - 1) % n)][(icons - 1) / n] == 1) {
        ans--;
      }
      if (y < icons / n || (y == icons / n && x < (icons % n))) {

      } else {
        ans++;
      }
    }
    a[x][y] ^= 1;
    cout << ans << '\n';
  }
}
