/**
 *    author:  vishnus
 *    created: 2022-04-19
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: determine the sum of all possible slice operations, then just add the sums to a hash set.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    unordered_set<long long> sums;
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    function<void(int, int)> Do = [&](int L, int R) {
      if (L > R) {
        return;
      }
      sums.insert(pref[R + 1] - pref[L]);
      if (L == R) {
        return;
      }
      int val = (a[R] + a[L]) / 2;
      int idx = (int) (upper_bound(a.begin() + L, a.begin() + R + 1, val) - (a.begin()) - 1);
      if (idx != R) {
        Do(L, idx);
      }
      Do(idx + 1, R);
    };
    Do(0, n - 1);
    while (q--) {
      int s;
      cin >> s;
      cout << (sums.contains((long long) s) ? "Yes" : "No") << '\n';
    }
  }
}
