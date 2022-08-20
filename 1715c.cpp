/**
 *    author:  vishnus
 *    created: 2022-08-20
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: define a joint as a location where two neighbouring elements are not equal.
// Find out how much that joint contributes to the total answer. Find total number 
// of subarrays that go through that joint (which is the product of the number of 
// starting points before the joint and ending points after the joint). Also add 1 
// to each subarray since the value of a subarray is the number of joints + 1. For 
// each query, simply recalculate the answer using the formula.

#define int long long

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &e : a) {
    cin >> e;
  }
  long long ans = n * (n + 1) / 2;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1]) {
      ans += (i + 1) * (n - i - 1);
    }
  }
  while (m--) {
    int i, x;
    cin >> i >> x;
    --i;
    if (i != 0) {
      if (a[i] == a[i - 1]) {
        if (x != a[i - 1]) {
          ans += (i) * (n - i);
        }
      } else {
        if (x == a[i - 1]) {
          ans -= (i) * (n - i);
        }
      }
    }
    if (i != n - 1) {
      if (a[i] == a[i + 1]) {
        if (x != a[i + 1]) {
          ans += (i + 1) * (n - i - 1);
        }
      } else {
        if (x == a[i + 1]) {
          ans -= (i + 1) * (n - i - 1);
        }
      }
    }
    a[i] = x;
    cout << ans << '\n';
  }
}
