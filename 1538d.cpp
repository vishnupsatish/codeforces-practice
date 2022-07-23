/**
 *    author:  vishnus
 *    created: 2022-07-23
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if k == 1, then one number must be divisible by the other and they must not
// equal each other. Otherwise, k >= 2, we know that, and the maximum number of times
// we can divide by each is the sum of all of the exponents of the prime factorization
// of both numbers. If k < the max answer, we can just combine two or more prime factors
// to reduce the number of times we divide.

int main() {
  #ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, k;
    cin >> a >> b >> k;
    if (k > 60) {
      cout << "NO" << '\n';
      continue;
    }
    if (a < b) {
      swap(a, b);
    }
    if (k == 1) {
      cout << ((a % b != 0 || a == b) ? "NO" : "YES") << '\n';
      continue;
    }
    int tot_cnt = 0;
    for (int i = 2; i * i <= a; i++) {
      while (a % i == 0) {
        a /= i;
        tot_cnt++;
      }
    }
    tot_cnt += (a != 1);
    for (int i = 2; i * i <= b; i++) {
      while (b % i == 0) {
        b /= i;
        tot_cnt++;
      }
    }
    tot_cnt += (b != 1);
    cout << (tot_cnt >= k ? "YES" : "NO") << '\n';
  }
}
