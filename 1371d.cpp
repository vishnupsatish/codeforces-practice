/**
 *    author:  vishnus
 *    created: 2022-04-29
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: iterate k and keep two variables, for current row and column. Increment row mod n, which
// will evenly spread out all rows (unless k % n != 0), and increment column mod n. If we have 
// reached the first row again, increment column since we cannot place ones where there was 
// already a one. The method of finding the row and column with the least number of ones does 
// not work since using that algorithm might cause a contradiction where the next (best and 
// logical) step already has a '1' at that location.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    int r = 0, c = 0;
    for (int i = 0; i < k; i++) {
      a[r][c] = 1;
      r++;
      c++;
      if (r == n) {
        c++;
      }
      r %= n;
      c %= n;
    }
    cout << 2 * (k % n != 0) << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[i][j];
      }
      cout << '\n';
    }
  }
}
