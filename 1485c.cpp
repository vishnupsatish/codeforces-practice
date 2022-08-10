/**
 *    author:  vishnus
 *    created: 2022-08-10
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: inequality and loop.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    long long ans = 0;
    int sq = (int) sqrt(x + 1) - 1;
    if (y <= sq) {
      cout << y * (y - 1) / 2 << '\n';
      continue;
    }
    ans += sq * (sq + 1) / 2;
    for (int cur = sq; cur >= 1; cur--) {
      if (cur == sq) {
        ans += cur * max(0, (min(y + 1, x / cur) - max(sq + 2, x / (cur + 1))));
      } else {
        ans += cur * max(0, (min(y + 1, x / cur) - x / (cur + 1)));
      }
    }
    cout << ans << '\n';
  }
}
