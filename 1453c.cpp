/**
 *    author:  vishnus
 *    created: 2022-08-18
**/
#include <bits/stdc++.h>

using namespace std;

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
    vector<vector<int>> a(n, vector<int>(n));
    vector<int> occ(10);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        char d;
        cin >> d;
        a[i][j] = (int) (d - '0');
        occ[a[i][j]]++;
      }
    }
    for (int d = 0; d < 10; d++) { // Each digit
      char term = " \n"[d == 9];
      if (occ[d] <= 1) {
        cout << 0 << term;
        continue;
      }
      int ans = 0;
      // First try to make one side parallel to the left/right side of the board
      {
        // Find first and last column that has 'digit'
        int fst = 1e9;
        int lst = -1;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if (a[j][i] == d) {
              fst = min(fst, i);
              lst = max(lst, i);
            }
          }
        }
        for (int i = 0; i < n; i++) { // Try to make column i the one with two of 'digit'
          // Find first and last row that has 'digit'
          int fst_r = 1e9;
          int lst_r = -1;
          for (int j = 0; j < n; j++) {
            if (a[j][i] == d) {
              fst_r = min(fst_r, j);
              lst_r = max(lst_r, j);
            }
          }
          if (fst_r == 1e9) {
            continue;
          }
          // Try to make the one digit after
          {
            // Change digit for top point
            if (lst != i) {
              ans = max(ans, lst_r * (lst - i));
            }
            // Change digit for bottom point
            if (lst != i) {
              ans = max(ans, (n - fst_r - 1) * (lst - i));
            }
            // Change digit for right point
            if (fst_r != lst_r) {
              ans = max(ans, (lst_r - fst_r) * (n - i - 1));
            }
          }
          // Try to make the one digit before
          {
            // Change digit for top point
            if (fst != i) {
              ans = max(ans, lst_r * (i - fst));
            }
            // Change digit for bottom point
            if (fst != i) {
              ans = max(ans, (n - fst_r - 1) * (i - fst));
            }
            // Change digit for right point
            if (fst_r != lst_r) {
              ans = max(ans, (lst_r - fst_r) * i);
            }
          }
        }
      }
      // Now try to make one side parallel to the bottom/top side of the board
      {
        // Find first and last row that has 'digit'
        int fst = 1e9;
        int lst = -1;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if (a[i][j] == d) {
              fst = min(fst, i);
              lst = max(lst, i);
            }
          }
        }
        for (int i = 0; i < n; i++) { // Try to make row i the one with two of 'digit'
          // Find first and last column that has 'digit'
          int fst_c = 1e9;
          int lst_c = -1;
          for (int j = 0; j < n; j++) {
            if (a[i][j] == d) {
              fst_c = min(fst_c, j);
              lst_c = max(lst_c, j);
            }
          }
          if (fst_c == 1e9) {
            continue;
          }
          // Try to make the one digit after
          {
            // Change digit for top point
            if (lst != i) {
              ans = max(ans, lst_c * (lst - i));
            }
            // Change digit for bottom point
            if (lst != i) {
              ans = max(ans, (n - fst_c - 1) * (lst - i));
            }
            // Change digit for right point
            if (fst_c != lst_c) {
              ans = max(ans, (lst_c - fst_c) * (n - i - 1));
            }
          }
          // Try to make the one digit before
          {
            // Change digit for top point
            if (fst != i) {
              ans = max(ans, lst_c * (i - fst));
            }
            // Change digit for bottom point
            if (fst != i) {
              ans = max(ans, (n - fst_c - 1) * (i - fst));
            }
            // Change digit for right point
            if (fst_c != lst_c) {
              ans = max(ans, (lst_c - fst_c) * i);
            }
          }
        }
      }
      cout << ans << term;
    }
  }
}
