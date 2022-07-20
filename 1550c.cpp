/**
 *    author:  vishnus
 *    created: 2022-07-19
**/
#include <bits/stdc++.h>

using namespace std;

// The condition is that point q must be inside the square bounded by points p or r. For that
// to be the case, b[i], b[j], and b[k] must be either non-decreasing or non-increasing. All
// subarrays of length 5 work, while you can brute-force all subarrays of lengths 3 and 4.

int main() {
  #ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) {
      cin >> e;
    }
    long long ans = n + max(0, n - 1) + max(0, n - 2) + max(0, n - 3);
    for (int i = 0; i < n - 2; i++) {
      if ((a[i] >= a[i + 1] && a[i + 1] >= a[i + 2]) || (a[i] <= a[i + 1] && a[i + 1] <= a[i + 2])) {
        ans--;
      }
    }
    for (int i = 0; i < n - 3; i++) {
      vector<vector<int>> combos = {{a[i], a[i + 1], a[i + 2]}, {a[i], a[i + 1], a[i + 3]}, {a[i], a[i + 2], a[i + 3]}, {a[i + 1], a[i + 2], a[i + 3]}};
      for (auto e : combos) {
        if ((e[0] >= e[1] && e[1] >= e[2]) || (e[0] <= e[1] && e[1] <= e[2])) {
          ans--;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
}
