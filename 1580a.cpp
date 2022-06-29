/**
 *    author:  vishnus
 *    created: 2022-06-28
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: We need to do this in n^3 total time. Create a 2D PSA counting the number of ones in a subrectangle.
// Loop the top and bottom boundaries. We can form a prefix minimum array of the best left boundary to take 
// since it is completely independent of the right boundary and the right boundary we choose does not have 
// an impact on the left boundary. pma[i] = the cost if we do
// X 1 1 1 1 1
// 1 0 0 0 0 0
// 1 0 0 0 0 0
// X 1 1 1 1 1
// For the right boundary, we loop it, use the prefix minimum value, and subtract what we overcounted by, and
// add the right ones column.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        a[i][j] = (c == '1');
      }
    }
    vector<vector<int>> opsa(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 && j == 0) {
          opsa[i + 1][j + 1] = a[i][j];
        } else if (i == 0) {
          opsa[i + 1][j + 1] = opsa[i + 1][j] + a[i][j];
        } else if (j == 0) {
          opsa[i + 1][j + 1] = opsa[i][j + 1] + a[i][j];
        } else {
          opsa[i + 1][j + 1] = opsa[i][j + 1] + opsa[i + 1][j] - opsa[i][j] + a[i][j];
        }
      }
    }
    auto QueryOne = [&](int r1, int c1, int r2, int c2) {
      return opsa[r2 + 1][c2 + 1] - opsa[r2 + 1][c1] - opsa[r1][c2 + 1] + opsa[r1][c1];
    };
    auto QueryZero = [&](int r1, int c1, int r2, int c2) {
      return (r2 - r1 + 1) * (c2 - c1 + 1) - QueryOne(r1, c1, r2, c2);
    };
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      for (int j = i + 4; j < n; j++) { // Iterate the top and bottom edges
        vector<int> pma(m); // Prefix minimum array for left edge
        for (int k = 0; k < m - 3; k++) {
          if (k == 0) {
            pma[k] = QueryZero(i + 1, k, j - 1, k) + QueryOne(i + 1, k + 1, j - 1, m - 1) + QueryZero(i, k + 1, i, m - 1) + QueryZero(j, k + 1, j, m - 1);
          } else {
            pma[k] = min(pma[k - 1], QueryZero(i + 1, k, j - 1, k) + QueryOne(i + 1, k + 1, j - 1, m - 1) + QueryZero(i, k + 1, i, m - 1) + QueryZero(j, k + 1, j, m - 1));
          }
        }
        for (int k = 3; k < m; k++) { // Iterate right edge
          ans = min(ans, pma[k - 3] - !a[i][k] - !a[j][k] - QueryZero(i, k + 1, i, m - 1) - QueryZero(j, k + 1, j, m - 1) - QueryOne(i + 1, k, j - 1, m - 1) + QueryZero(i + 1, k, j - 1, k));
        }
      }
    }
    cout << ans << '\n';
  }
}
