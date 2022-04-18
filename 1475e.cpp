/**
 *    author:  vishnus
 *    created: 2022-04-18
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: we know that Masha will pick the k bloggers with the most followers. Sort. Now it is a question
// of, given n numbers, how many ways can we choose exactly k numbers such that the sum is maximized?
// Given the initial combination, we cannot choose something larger (since it is chosen) or smaller
// (since the sum will reduce), so we must choose different occurrences of the same number. Count how
// many occurrences of a number we use (let that be c), then use combinations(number of total occurrences
// of a number we use, c) to determine the final answer.

const int md = (int) 1e9 + 7;

long long memo[1003];

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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    sort(a.begin(), a.end(), greater<>());
    unordered_map<int, int> mscnt;
    for (int i = 0; i < k; i++) {
      mscnt[a[i]]++;
    }
    long long ans = 1;
    for (auto [k, v] : mscnt) {
      ans *= nCr(cnt[k], v);
      ans %= md;
    }
    cout << ans << '\n';
  }
}
