/**
*  author:  vishnus
*  created: 2022-08-29
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Try all strings that differ from the first string by one character.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &e : s) {
      cin >> e;
    }
    string ans;
    auto Check = [&](string cur) {
      for (int i = 0; i < n; i++) {
        int dif = 0;
        for (int j = 0; j < m; j++) {
          dif += s[i][j] != cur[j];
        }
        if (dif > 1) {
          return;
        }
      }
      ans = cur;
    };
    Check(s[0]);
    for (int i = 0; i < m; i++) {
      for (char c = 'a'; c <= 'z'; c++) {
        string ne = s[0];
        ne[i] = c;
        Check(ne);
      }
    }
    if (ans.empty()) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans << '\n';
  }
}
