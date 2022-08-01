/**
 *    author:  vishnus
 *    created: 2022-08-01
**/
#include <bits/stdc++.h>

using namespace std;

// a[i] = val[i] * greater square number that is a factor. If the 'val' value is the same for
// two numbers, then their product is a perfect square. Why? Each exponent in the prime
// factorization must be even. So, the perfect square aspect is taken care of, while the other
// number's factors have no prime factors that have an even exponent, so when they're multiplied
// together their exponents will be even.

const int mx = (int) 1e7;

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  vector<int> val(mx + 1);
  for (int i = 0; i <= mx; i++) {
    val[i] = i;
  }
  vector<int> prime(mx + 1, 1);
  for (int i = 2; i * i <= mx; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= mx; j += i) {
        prime[j] = 0;
        while (val[j] % (i * i) == 0) {
          val[j] /= (i * i);
        }
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &e : a) {
      cin >> e;
    }
    int ans = 1;
    unordered_set<int> val_exists = {val[a[0]]};
    int prev = 0;
    for (int i = 1; i < n; i++) {
      if (val_exists.contains(val[a[i]])) {
        for (int j = prev; j < i; j++) {
          val_exists.erase(val[a[j]]);
        }
        prev = i;
        ans++;
      }
      val_exists.insert(val[a[i]]);
    }
    cout << ans << '\n';
  }
}
