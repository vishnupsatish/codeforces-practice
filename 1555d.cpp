/**
 *    author:  vishnus
 *    created: 2022-03-25
**/
#include <bits/stdc++.h>

using namespace std;

// Optimal idea: abcabc, or bcabca,.. etc (6 possibilities).
// Use PSA to calculate the number of operations needed for each.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<char> s(n);
  vector<vector<vector<int>>> pref(3, vector<vector<int>>(3, vector<int>(n + 1)));
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        pref[j][k][i + 1] = pref[j][k][i];
      }
    }
    pref[s[i] - 'a'][i % 3][i + 1]++;
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    --l; --r;
    int cnt = r - l + 1;
    int ans = cnt;
    ans = min(ans, cnt - (pref[0][0][r + 1] - pref[0][0][l]) - (pref[1][1][r + 1] - pref[1][1][l]) - (pref[2][2][r + 1] - pref[2][2][l]));
    ans = min(ans, cnt - (pref[0][1][r + 1] - pref[0][1][l]) - (pref[1][0][r + 1] - pref[1][0][l]) - (pref[2][2][r + 1] - pref[2][2][l]));
    ans = min(ans, cnt - (pref[0][1][r + 1] - pref[0][1][l]) - (pref[1][2][r + 1] - pref[1][2][l]) - (pref[2][0][r + 1] - pref[2][0][l]));
    ans = min(ans, cnt - (pref[0][2][r + 1] - pref[0][2][l]) - (pref[1][1][r + 1] - pref[1][1][l]) - (pref[2][0][r + 1] - pref[2][0][l]));
    ans = min(ans, cnt - (pref[0][0][r + 1] - pref[0][0][l]) - (pref[1][2][r + 1] - pref[1][2][l]) - (pref[2][1][r + 1] - pref[2][1][l]));
    ans = min(ans, cnt - (pref[0][2][r + 1] - pref[0][2][l]) - (pref[1][0][r + 1] - pref[1][0][l]) - (pref[2][1][r + 1] - pref[2][1][l]));
    cout << ans << '\n';
  }
}
