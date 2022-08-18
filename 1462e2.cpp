/**
 *    author:  vishnus
 *    created: 2022-08-17
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: simple combinatorics. Sort, binary search for the max number that can be chosen if 
// 'i' is chosen. Then use nCr to choose m - 1 numbers from that range. Add all of the answers.

const int md = (int) 1e9 + 7;

long long memo[200001];

long long fact(int numb) {
  if (numb <= 1) {
    return 1;
  }
  if (memo[numb] != 0) {
    return memo[numb];
  }
  return memo[numb] = (numb * fact(numb - 1)) % md;
}

long long pow_mod(long long x, int p) {
  if (p == 0) {
    return 1;
  }
  long long c = pow_mod(x, p / 2) % md;
  if (p & 1) {
    return (((c * c) % md) * x) % md;
  }
  return (c * c) % md;
}

long long nCr(int n_, int r) {
  if (n_ < r) {
    return 0;
  }
  if (n_ == r) {
    return 1;
  }
  long long numerator = fact(n_) % md;
  long long denominator = (fact(r) * fact(n_ - r)) % md;
  return (numerator * pow_mod(denominator, md - 2)) % md;
}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto &e : a) {
      cin >> e;
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int idx = (int) (upper_bound(a.begin(), a.end(), a[i] + k) - a.begin()) - 1;
      ans += nCr(idx - i, m - 1);
      ans %= md;
    }
    cout << ans << '\n';
  }
}
