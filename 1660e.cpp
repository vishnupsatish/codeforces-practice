/**
 *    author:  vishnus
 *    created: 2022-04-20
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: when we cyclically shift, if a one appears in column j in row i, it must appear in
// column (j + 1) % n in row i + 1. Loop all possible positions of the first row's one (where
// the diagonal starts) and calculate the answer for each.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<int> cnt(n); // Number of ones in the ith row
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < n; j++) {
        a[i][j] = (s[j] == '1');
        cnt[i] += a[i][j];
      }
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) { // Start a diagonal at i
      int cur = i;
      int ca = 0;
      for (int j = 0; j < n; j++) {
        ca += cnt[j];
        if (a[j][cur] == 1) {
          ca--;
        } else {
          ca++;
        }
        cur++;
        cur %= n;
      }
      ans = min(ans, ca);
    }
    cout << ans << '\n';
  }
}
