/**
 *    author:  vishnus
 *    created: 2022-07-14
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/a/1dNZD3E

int main() {
  #ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &e : a) {
      cin >> e;
    }
    long long ans = -1e18;
    for (long long i = max(0, n - 2 * k - 2); i < n; i++) {
      for (long long j = i + 1; j < n; j++) {
        ans = max(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]));
      }
    }
    cout << ans << '\n';
  }
}
