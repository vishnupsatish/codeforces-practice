/**
 *    author:  vishnus
 *    created: 2022-04-22
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: We need to place radio towers such that the distance to the right side
// and to the left side are equal (we can choose tower powers accordingly). This
// is equivalent to finding the number of ways to sum to n using only odd numbers
// (with order mattering). The number of ways to sum to n using only odd numbers
// is equal to fib(n), since for each number, we can take the number of ways to
// sum to n - 1 (and do + 1 to each way) and we can take the number of ways to
// sum to n - 2 (and do the last number += 2). This would give all of the permutations
// of odd numbers since n - 1 (then + 1) and n - 2 (then last number + 2) provides
// all possibilities of last numbers, and the other numbers' possibilities
// are taken care of by n - 1 and n - 2.

const int md = 998244353;

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long denominator = pow_mod(2, n);
  vector<long long> dp(n);
  dp[0] = dp[1] = 1;
  for (int i = 2; i < n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % md;
  }
  cout << (dp[n - 1] * pow_mod(denominator, md - 2)) % md << '\n';
}
