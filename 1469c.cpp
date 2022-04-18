/**
 *    author:  vishnus
 *    created: 2022-04-18
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: maintain a segment of possible values. If this segment is empty, then there is no answer.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    int l = h[0], r = h[0];
    bool ok = true;
    for (int i = 1; i < n; i++) {
      l = max(h[i], l - k + 1);
      r = min(h[i] + k - 1, r + k - 1);
      if (l > r) {
        ok = false;
        break;
      }
    }
    ok = h[n - 1] >= l && h[n - 1] <= r && ok;
    cout << (ok ? "YES" : "NO") << '\n';
  }
}
