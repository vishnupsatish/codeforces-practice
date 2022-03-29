/**
 *    author:  vishnus
 *    created: 2022-03-29
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Normal brute-force of all subarrays is O(N^3). Start from the middle of a
// reversed segment, so when we add the values, it is O(1). Try both odd and even lengths.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<long long> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i] * b[i];
  }
  long long ans = pref[n];
  for (int i = 1; i < n; i++) {
    int l = i - 1, r = i + 1;
    long long val = a[i] * b[i];
    while (l >= 0 && r < n) {
      val += a[l] * b[r] + b[l] * a[r];
      ans = max(ans, val + pref[l] + (pref[n] - pref[r + 1]));
      l--;
      r++;
    }
    l = i - 1, r = i;
    val = 0;
    while (l >= 0 && r < n) {
      val += a[l] * b[r] + a[r] * b[l];
      ans = max(ans, val + pref[l] + (pref[n] - pref[r + 1]));
      l--;
      r++;
    }
  }
  cout << ans << '\n';
}
