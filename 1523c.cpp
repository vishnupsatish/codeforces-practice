/**
 *    author:  vishnus
 *    created: 2022-03-29
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Store the current level. If a[i] == 1, then make a new level.
// Otherwise, keep decrementing level until we find a value that works.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> ans(n);
    int cl = 0;
    ans[0] = {1};
    for (int i = 1; i < n; i++) {
      if (a[i] == 1) {
        ans[i] = ans[i - 1];
        ans[i].push_back(1);
        cl++;
      } else {
        while (cl >= 0) {
          if (a[i] == ans[i - 1][cl] + 1) {
            ans[i] = vector<int>(ans[i - 1].begin(), ans[i - 1].begin() + cl + 1);
            ans[i][cl] = a[i];
            break;
          }
          cl--;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (int) ans[i].size(); j++) {
        if (j > 0) {
          cout << '.';
        }
        cout << ans[i][j];
      }
      cout << '\n';
    }
  }
}
