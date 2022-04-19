/**
 *    author:  vishnus
 *    created: 2022-04-19
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: N^2, try all positions which the robot goes through as the position to replace the obstacle.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    set<pair<int, int>> p;
    int sx = 0, sy = 0;
    for (int i = 0; i < n; i++) {
      sy += (s[i] == 'U');
      sy -= (s[i] == 'D');
      sx += (s[i] == 'R');
      sx -= (s[i] == 'L');
      p.emplace(sx, sy);
    }
    bool ok = false;
    for (auto [ox, oy] : p) {
      int cx = 0, cy = 0;
      for (int i = 0; i < n; i++) {
        cy += (s[i] == 'U') - (s[i] == 'U' && ox == cx && oy == cy + 1);
        cy -= (s[i] == 'D') - (s[i] == 'D' && ox == cx && oy == cy - 1);
        cx += (s[i] == 'R') - (s[i] == 'R' && ox == cx + 1 && oy == cy);
        cx -= (s[i] == 'L') - (s[i] == 'L' && ox == cx - 1 && oy == cy);
      }
      if (cx == 0 && cy == 0) {
        cout << ox << ' ' << oy << '\n';
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << "0 0" << '\n';
    }
  }
}
