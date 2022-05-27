/**
 *    author:  vishnus
 *    created: 2022-05-27
**/
#include <bits/stdc++.h>

using namespace std;

// Key idea: some number of odd operations, some even. Odd can be increased (not even). Find the minimum value. I used gross formulas.

#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> h(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> h[i];
      mx = max(mx, h[i]);
    }
    int dif = 0;
    int o = 0, e = 0; // Odd and even differences, minimize od + ev + abs(ev - od). If ev--, then od += 2, how? If ev++, od -= 2.
    for (int i = 0; i < n; i++) {
      o += (mx - h[i]) & 1;
      e += (mx - h[i]) / 2;
      dif += (mx - h[i]);
    }
    auto Get = [](int od, int ev) -> int {
      if (od > ev) {
        return od + ev + od - ev - 1;
      }
      return od + ev + ev - od;
    };
    int ans;
    if (o > e) {
      ans = Get(o, e);
    } else {
      ans = 2 * dif / 3 + (2 * dif % 3 != 0);
    }
    dif = 0;
    mx++;
    o = 0;
    e = 0;
    for (int i = 0; i < n; i++) {
      o += (mx - h[i]) & 1;
      e += (mx - h[i]) / 2;
      dif += (mx - h[i]);
    }
    if (o > e) {
      ans = min(ans, Get(o, e));
    } else {
      ans = min(ans, 2 * dif / 3 + (2 * dif % 3 != 0));
    }
    cout << ans << '\n';
  }
}
