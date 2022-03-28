/**
 *    author:  vishnus
 *    created: 2022-03-27
**/
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<long long> primes;
  for (int i = 2; i <= 100; i++) {
    bool pr = true;
    for (int j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) {
        pr = false;
        break;
      }
    }
    if (pr) {
      primes.push_back(i);
    }
  }
  map<long long, pair<long long, long long>> num;
  num[3] = {2, 2};
  vector<long long> cur = {2};
  long long cum = 2;
  int cv = 3, prev = 2;
  while (cv <= 43) {
    int val = prev;
    for (auto e : cur) {
      if (val % e == 0) {
        val /= e;
      }
    }
    if ((cum * val % cv) != 0) {
      for (auto e : primes) {
        if (cv % e != 0) {
          cur.push_back(val);
          cum *= val;
          num[cv] = {cum, e};
          break;
        }
      }
      prev = cv;
    }
    cv++;
  }
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    long long ans = n + (n & 1);
    for (auto [k, v] : num) {
      long long mk = k % MOD;
      long long strt = v.first, mult = v.second;
      if (strt > n) {
        break;
      }
      long long dif = (strt * mult) - strt;
      if (dif != strt) {
        ans += ((n - strt) / dif + 1) * mk;
      } else {
        ans += (n / dif) * mk;
      }
      ans %= MOD;
      if (k & 1) {
        ans += 2 * MOD;
        long long frm;
        for (int i = (int) k + 1; i <= 50; i++) {
          if (num.contains(i)) {
            frm = num[i].first;
            break;
          }
        }
        ans -= ((n / frm) * mk) % MOD;
      }
      ans %= MOD;
    }
    cout << ans << '\n';
  }
}
