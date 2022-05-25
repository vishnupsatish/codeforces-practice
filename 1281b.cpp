/**
 *    author:  vishnus
 *    created: 2022-05-25
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: loop s. (It is implied that s[i] >= c[i] due to our very first check).
// Try making s[i] some letter below c[i]. One exception is we can make it equal
// to c[i] then check if it is a prefix of c[i]. If s[i] > c[i] and we're not
// able to do this then there is no solution. If s[i] == c[i] and we can't do
// this, keep trying.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, c;
    cin >> s >> c;
    int n = (int) s.size();
    int m = (int) c.size();
    if (s < c) {
      cout << s << '\n';
      continue;
    }
    vector<vector<int>> idx(26);
    for (int i = 0; i < n; i++) {
      idx[s[i] - 'A'].push_back(i);
    }
    bool k = false;
    for (int i = 0; i < min(n, m); i++) {
      if (s[i] >= c[i]) {
        bool ok = false;
        for (int j = 0; j <= c[i] - 'A'; j++) {
          if (j == c[i] - 'A') {
            if (!idx[j].empty() && idx[j].back() > i) {
              swap(s[i], s[idx[j].back()]);
              if (s < c) {
                ok = true;
                break;
              }
              swap(s[i], s[idx[j].back()]);
            }
          } else {
            if (!idx[j].empty() && idx[j].back() > i) {
              ok = true;
              swap(s[i], s[idx[j].back()]);
              break;
            }
          }
        }
        if (ok) {
          cout << s << '\n';
          k = true;
          break;
        } else if (s[i] > c[i]) {
          break;
        }
      }
    }
    if (!k) {
      cout << "---" << '\n';
    }
  }
}
