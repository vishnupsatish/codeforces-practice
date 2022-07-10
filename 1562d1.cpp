/**
 *    author:  vishnus
 *    created: 2022-07-10
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/a/nPqFq5Z

int main() {
  #ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
      char x;
      cin >> x;
      s[i] = (x == '+' ? 1 : -1);
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + s[i] * pow(-1, i);
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      --l; --r;
      if (r - l + 1 & 1) {
        cout << 1 << '\n';
      } else if (pref[r + 1] - pref[l] == 0) {
        cout << 0 << '\n';
      } else {
        cout << 2 << '\n';
      }
    }
  }
}
