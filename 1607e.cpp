/**
 *    author:  vishnus
 *    created: 2022-03-23
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: greedily maintain the current position and starting position, and change them
// as needed. Once the starting position cannot be changed or the starting position
// plus the maximum downward/upward movement or maximum left/right movement is outside
// the board, we must stop.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    int sr = 1, sc = 1, cr = 1, cc = 1, mr = 0, md = 0;
    bool ok = true;
    set<int, greater<>> lmr, lmd;
    set<int> smr, smd;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == 'L') {
        if (cc == 1) {
          sc++;
        } else {
          cc--;
        }
        mr--;
      } else if (s[i] == 'R') {
        if (cc == m) {
          sc--;
        } else {
          cc++;
        }
        mr++;
      } else if (s[i] == 'U') {
        if (cr == 1) {
          sr++;
        } else {
          cr--;
        }
        md--;
      } else if (s[i] == 'D') {
        if (cr == n) {
          sr--;
        } else {
          cr++;
        }
        md++;
      }
      lmr.emplace(mr);
      smr.emplace(mr);
      lmd.emplace(md);
      smd.emplace(md);
      if (sr > n || *lmd.begin() + sr > n) {
        sr--;
        ok = false;
      } else if (sr < 1 || *smd.begin() + sr < 1) {
        sr++;
        ok = false;
      } else if (sc > m || *lmr.begin() + sc > m) {
        sc--;
        ok = false;
      } else if (sc < 1 || *smr.begin() + sc < 1) {
        sc++;
        ok = false;
      }
      if (!ok) {
        break;
      }
    }
    cout << sr << ' ' << sc << '\n';
  }
}
