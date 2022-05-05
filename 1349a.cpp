/**
 *    author:  vishnus
 *    created: 2022-05-05
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: GCD is basically taking the prime factorization and the minimum of each pair of powers
// of a base. LCM is the same, except instead of minimum it is maximum. When we take the LCMs of
// all pairs of elements, we are taking the maximum of all pairs of prime powers. Then, we are 
// taking the GCD of that. For each prime, the multiset containing the LCMs will have a minimum
// power of the second minimum power of all elements. Why? The minimum LCM we can do for a pair
// is least power, second least power, and taking the LCM of that leads to second least power.
// If more than one power is 0, then that number doesn't contribute to the answer. Therefore,
// we can iterate each prime then iterate a, and take the second-least power for that prime 
// (in a) and multiply answer by it. As an optimization, if there are more than two numbers 
// that do not contain that prime in its factorization, just break.

const int maxval = (int) 2e5 + 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> sieve(maxval, 1);
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i * i < maxval; i++) {
    if (sieve[i]) {
      for (int j = i * i; j < maxval; j += i) {
        sieve[j] = 0;
      }
    }
  }
  vector<int> primes;
  for (int i = 0; i < maxval; i++) {
    if (sieve[i]) {
      primes.push_back(i);
    }
  }
  long long ans = 1;
  for (auto p : primes) {
    vector<int> vals;
    int nt = 0;
    for (auto e : a) {
      if (nt >= 2) {
        break;
      }
      if (e % p != 0) {
        nt++;
        continue;
      }
      int el = e;
      int cnt = 0;
      while (el % p == 0) {
        el /= p;
        cnt++;
      }
      vals.push_back(cnt);
    }
    if (nt == 0) {
      sort(vals.begin(), vals.end());
      ans *= pow(p, vals[1]);
    } else if (nt == 1) {
      sort(vals.begin(), vals.end());
      ans *= pow(p, vals[0]);
    }
  }
  cout << ans << '\n';
}
