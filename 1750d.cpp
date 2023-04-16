#include <bits/stdc++.h>

using namespace std;

// Editorial NOT used!!

// Idea: the answer is 0 if future numbers aren't a divisor of previous ones. Why? That
// implies that new prime factors were added to future numbers, but the b[i] value for 
// earlier ones cannot include that GCD value therefore it's impossible to work with. 
// Now, for each array value, we can calculate the number of possibilities as follows: 
// we cannot add prime factors that exist in the previous value but don't exist in the 
// current value, since that would make the GCD greater than a[i]. But, we can add prime 
// factors that aren't in this set. So, we can multiply a[i] by any value to get b[i] 
// (except numbers that are made up of the forbidden set of prime factors). So, we use 
// inclusion exclusion to get rid of all multiples of the forbidden set of prime factors
// and independently multiply each number of possibilities for each value in the array.

const int md = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    bool done = false;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
      if (a[i - 1] % a[i] != 0) {
        done = true;
      }
    }
    if (done) {
      cout << 0 << '\n';
      continue;
    }
    long long ans = 1;
    for (int i = 1; i < n; i++) {
      int div = a[i - 1] / a[i];
      int cur = div;
      unordered_set<int> pf;
      while (cur % 2 == 0) {
        pf.insert(2);
        cur /= 2;
      }
      for (int j = 3; j <= (int) sqrt(cur); j += 2) {
        while (cur % j == 0) {
          pf.insert(j);
         cur /= j;
        }
      }
      if (cur > 2) {
        pf.insert(cur);
      }
      vector<int> pfl;
      for (auto p : pf) {
        pfl.push_back(p);
      }
      long long tot = m / a[i];
      long long cuse = tot;
      // Principle of inclusion/exclusion
      int nopr = (int) pfl.size();
      for (int j = 1; j <= (int) pow(2, nopr) - 1; j++) {
        bitset<10> sts(j);
        if (__builtin_popcountll(j) & 1) { // Get rid of this subset
          long long vrm = 1;
          for (int k = 0; k <= nopr - 1; k++) {
            if (sts[k]) {
              vrm *= pfl[k];
            }
          }
          cuse -= tot / vrm;
          cuse = (cuse + md) % md;
        } else { // Over-got-rid-of!! Add it back!
          long long vrm = 1;
          for (int k = 0; k <= nopr - 1; k++) {
            if (sts[k]) {
              vrm *= pfl[k];
            }
          }
          cuse += tot / vrm;
          cuse = (cuse + md) % md;
        }
      }
      ans = (ans * cuse) % md;
    }
    cout << ans << '\n';
  }
}
