/**
 *    author:  vishnus
 *    created: 2022-05-12
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: good problem for understanding modular arithmetic. If n <= m, then we can simply calculate the answer
// using an O(n^2) method. If n > m, the answer will be 0. Why? because of how modular arithmetic works. If we
// first do a[i] % m for all i, there will be at least two indices i with the same value. Why? There are only m
// possible values if we mod and n > m so at least one value with repeat. Then when we multiply, the product of
// everything will be zero since there are two indices with the same value (and multiplying anything by the
// difference of those two values gives 0).

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n > m) {
    cout << 0 << '\n';
    return 0;
  }
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans *= abs(a[i] - a[j]);
      ans %= m;
    }
  }
  cout << ans << '\n';
}
