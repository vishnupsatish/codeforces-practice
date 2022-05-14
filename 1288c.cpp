/**
 *    author:  vishnus
 *    created: 2022-05-14
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Combinatorics. Using logic we know that the smallest element in b must exceed
// the largest element in a. We can try to find the number of ways to make i (all i
// from 1 to n) the largest element in a (and the smallest in j), then use an O(n^2)
// loop to make i the largest element in a and j the smallest element in b. (multiply
// those values). Now, we need to find the number of different arrays that exist such that
// i is the largest element in (sorted) a. The other m - 1 elements must be in the range
// [1, i] and sorted. We can model this as an equation. m - 1 = cnt(1) + cnt(2) + ... +
// cnt(i) where cnt(k) represents the number of occurrences of the number i and cnt(k)
// is a non-negative number. This is calculated by using stars and bars and works and the
// formula is as follows: (i + m - 2) choose (i - 1). How does this work?
// https://imgur.com/a/TIWd4Pj

const int md = (int) 1e9 + 7;

long long memo[1010];

long long fact(int numb) {
  if (numb == 1) {
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
  if (n_ == r) {
    return 1;
  }
  long long numerator = fact(n_) % md;
  long long denominator = (fact(r) * fact(n_ - r)) % md;
  return (numerator * pow_mod(denominator, md - 2)) % md;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  long long ans = 0;
  unordered_map<int, long long> va, vb; // Number of ways to make [key] the largest/smallest value in 'a'/'b' respectively
  for (int lg = 1; lg <= n; lg++) { // Loop largest element in 'a'
    long long cur = nCr(lg + m - 2, lg - 1);
    va[lg] = max(1ll, cur);
  }
  for (int sm = 1; sm <= n; sm++) { // Loop smallest element in 'b'
    long long cur = nCr((n - sm + 1) + m - 2, (n - sm + 1) - 1);
    vb[sm] = max(1ll, cur);
  }
  for (int i = 1; i <= n; i++) { // Make i the largest element in 'a'
    for (int j = i; j <= n; j++) { // Make j the smallest element in 'b'
      ans += (va[i] * vb[j]) % md;
      ans %= md;
    }
  }
  cout << ans << '\n';
}
