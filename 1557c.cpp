/**
 *    author:  vishnus
 *    created: 2022-07-14
**/
#include <bits/stdc++.h>

using namespace std;

// NOTE: WE ARE LOOPING EACH DIGIT OF THE BINARY REPRESENTATION NOT EACH VALUE OF A.
// Idea is combinatorics, can't explain everything since it is a lot to go through.

const int md = (int) 1e9 + 7;

long long fact[1000002];

long long pow_mod(long long x, long long p) {
  if (p == 0) {
    return 1;
  }
  long long c = pow_mod(x, p / 2) % md;
  if (p & 1) {
    return (((c * c) % md) * x) % md;
  }
  return (c * c) % md;
}

long long div_mod(long long num, long long den) {
  return (num * pow_mod(den, md - 2)) % md;
}

int main() {
  #ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif
  fact[0] = 1;
  fact[1] = 1;
  for (long long i = 2; i <= 1000000; i++) {
    fact[i] = (fact[i - 1] * i) % md;
  }
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, k;
    cin >> n >> k;
    // Calculate the answer if end[i] == 0 for both & and xor (1 appears an even number of times in each element of a at the ith position and there is at least 1 zero)
    long long zero_answer = 0;
    // i ones
    for (int i = 0; i <= n - 1; i += 2) {
      zero_answer += div_mod(fact[n], fact[i] * fact[n - i] % md);
      zero_answer %= md;
    }
    if (n & 1) { // If n is odd, every element must be the same
      cout << (pow_mod(zero_answer + 1, k)) % md << '\n';
    } else { // If n is even, we can make every element equal 0 or a prefix equal 0 and one element greater
      long long ans = 0;
      // Make i elements of the prefix the same in end[i] for both & and xor
      for (int i = 0; i < k; i++) {
        long long same_before = pow_mod(zero_answer, i);
        long long greater = 1;
        long long anything_after = pow_mod(2, ((k - i - 1) * n));
        ans += (((same_before * greater) % md) * anything_after) % md;
        ans %= md;
      }
      long long everything_same = pow_mod(zero_answer, k);
      cout << (ans + everything_same) % md << '\n';
    }
  }
}
