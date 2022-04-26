/**
 *    author:  vishnus
 *    created: 2022-04-26
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: If a number is even, you can take number, number - 2 and that is a
// valid combination. If the number is composite, you can take the least
// factor (let that be 'f') of the number, and do number, number - f. f =
// gcd(number, number - f). f will be less than number / f since f is the
// least factor of number, and (number - f) / f will be one less than
// number - f. The structure will therefore be f, a, a - 1, and this triple
// will always form a triangle. If the number is prime, only number^2 will
// work since 1 will be one of the numbers in the triple, and therefore,
// the other two numbers must be the same.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> sieve((int) 1e6 + 1, 1);
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i * i <= (int) 1e6; i++) {
    if (sieve[i]) {
      for (int j = i * i; j <= (int) 1e6; j += i) {
        sieve[j] = 0;
      }
    }
  }
  vector<int> primes;
  for (int i = 0; i <= (int) 1e6; i++) {
    if (sieve[i]) {
      primes.push_back(i);
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int s = (int) sqrt(n);
    int prr = (int) (upper_bound(primes.begin(), primes.end(), n) - primes.begin() - 1);
    int prl = (int) (upper_bound(primes.begin(), primes.end(), s) - primes.begin() - 1);
    cout << prr - prl + 1 << '\n';
  }
}
