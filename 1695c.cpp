/**
 *    author:  vishnus
 *    created: 2022-06-28
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: If m + n is even, then we will be going through an odd number of squares, meaning the
// sum will never be zero. Otherwise, we can find the minimum and maximum sums achievable using
// simple DP. If 0 lies in the range of the minimum and maximum sums, then it is achievable.
// Why? Because by changing one cell we visit to another one, we change the sum by either 0, -2,
// 2. This implies that by changing some number of the cells we visit, we will reach zero since
// we can change the max sum into the min sum, and zero lies in between that.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &r : a) {
      for (auto &e : r) {
        cin >> e;
      }
    }
    if (!(n + m & 1)) {
      cout << "NO" << '\n';
      continue;
    }
    vector<vector<int>> mindp(n, vector<int>(m)), maxdp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 && j == 0) {
          mindp[i][j] = a[i][j];
          maxdp[i][j] = a[i][j];
        } else if (i == 0) {
          mindp[i][j] = a[i][j] + mindp[i][j - 1];
          maxdp[i][j] = a[i][j] + maxdp[i][j - 1];
        } else if (j == 0) {
          mindp[i][j] = a[i][j] + mindp[i - 1][j];
          maxdp[i][j] = a[i][j] + maxdp[i - 1][j];
        } else {
          mindp[i][j] = a[i][j] + min(mindp[i - 1][j], mindp[i][j - 1]);
          maxdp[i][j] = a[i][j] + max(maxdp[i - 1][j], maxdp[i][j - 1]);
        }
      }
    }
    cout << (maxdp[n - 1][m - 1] >= 0 && mindp[n - 1][m - 1] <= 0 ? "YES" : "NO") << '\n';
  }
}
