/**
*  author:  vishnus
*  created: 2022-09-02
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: from a logical sense, it is optimal to minimize first whoever faces 1 and loses, then whoever 
// faces those people, and so on. Basically, we can create a binary tree where an edge is 1 if that 
// person wins that game and 0 otherwise. We realize that the sum of a path from the root to a certain
// node must be >= n - k to be able to make that node win. So basically, that path must have at least
// n - k ones. So we can use the sum of combinations to put 1 one, 2 ones, all the way to n - k ones
// and that is the answer.

const int md = (int) 1e9 + 7;

long long memo[1000000];

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
  int n, k;
  cin >> n >> k;
  k = min(k, n);
  long long ans = 1;
  for (int i = 1; i <= k; i++) {
    ans += nCr(n, i);
    ans %= md;
  }
  cout << ans << '\n';
}
