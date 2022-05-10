/**
 *    author:  vishnus
 *    created: 2022-05-10
**/
#include <bits/stdc++.h>

using namespace std;

// Once we select a start node, it is always optimal to go in order and kill enemy i before killing
// (i + 1) % n, since that would reduce the number of bullets that we have to use. The number of
// bullets to kill enemy i is equal to max(0, a[i] - b[i - 1]). When we select a start node, instead
// of max(0, a[i] - b[i - 1]), the value becomes just a[i]. So the start node we select must minimize
// a[i] - max(0, a[i] - b[i - 1])

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    int idx = 0;
    long long val = 1e18;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] - max(0ll, a[i] - b[(i - 1 + n) % n]) < val) {
        idx = i;
        val = a[i] - max(0ll, a[i] - b[(i - 1 + n) % n]);
      }
      ans += max(0ll, a[i] - b[(i - 1 + n) % n]);
    }
    ans += a[idx] - max(0ll, a[idx] - b[(idx - 1 + n) % n]);
    cout << ans << '\n';
  }
}
