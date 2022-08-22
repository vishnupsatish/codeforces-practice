/**
*  author:  vishnus
*  created: 2022-08-22
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/a/cZpIUs6

const int md = (int) 1e9 + 7;

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
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = (int) (s[i] - '0');
  }
  vector<long long> pref_val(n + 1);
  vector<long long> suf_val(n + 1);
  vector<long long> suf_sums(n + 1);
  for (int i = 0; i < n; i++) {
    pref_val[i + 1] = (((pref_val[i] * 10) % md) + a[i]) % md;
  }
  for (int i = n - 1; i >= 0; i--) {
    suf_val[i] = (((a[i] * pow_mod(10, n - i - 1)) % md) + suf_val[i + 1]) % md;
    suf_sums[i] = (suf_sums[i + 1] + suf_val[i]) % md;
  }
  long long ans = 0;
  vector<long long> coef(n + 1);
  for (int i = 0; i < n; i++) {
    coef[i + 1] = (coef[i] + pow_mod(10, i)) % md;
  }
  for (int i = 0; i < n; i++) {
    ans += (((pref_val[i] * coef[n - i]) % md) + suf_sums[i + 1]) % md;
    ans %= md;
  }
  cout << ans << '\n';
}
