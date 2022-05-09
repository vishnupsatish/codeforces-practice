/**
 *    author:  vishnus
 *    created: 2022-05-09
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Let L be lcm(a, b). If the condition works for some x, it also works for some
// x mod L. Why? L mod a and L mod b is zero (so is 0 mod a and 0 mod b), and mod repeats
// at 0 -> L - 1, L -> 2L - 1, and so on, so we can use this recurrence.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, q;
    cin >> a >> b >> q;
    int lc = lcm(a, b);
    vector<int> pref(lc + 1);
    for (int i = 0; i < lc; i++) {
      if (i > 0) {
        pref[i] += pref[i - 1];
      }
      pref[i] += ((i % a) % b != (i % b) % a);
    }
    while (q--) {
      auto Count = [&](long long R) -> long long {
        return pref[lc - 1] * (R / lc) + pref[R % lc];
      };
      long long l, r;
      cin >> l >> r;
      cout << Count(r) - Count(l - 1) << ' ';
    }
    cout << '\n';
  }
}
