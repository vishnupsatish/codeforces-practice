/**
 *    author:  vishnus
 *    created: 2022-05-25
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: optimal solution is to take segments of length 'k'. Loop the number 
// of elements we are attempting to take, and it is optimal to take the most 
// segments of length k as we can, and make the remaining prefix taken 
// individually. Use a modular PSA to make all operations constant time.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<vector<int>> prefm(k, vector<int>(n / k + 1));
    vector<int> pref(n + 1);
    for (int i = k - 1; i < n; i++) {
      prefm[i % k][(i + 1) / k] = prefm[i % k][(i + 1) / k - 1] + a[i];
    }
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) { // Take all up to and including i
      int cur;
      if (i >= k - 1) {
        cur = prefm[i % k][(i + 1) / k] + pref[(i + 1) % k];
      } else {
        cur = pref[i + 1];
      }
      if (cur <= p) {
        ans = i + 1;
      }
    }
    cout << ans << '\n';
  }
}
