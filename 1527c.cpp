/**
 *    author:  vishnus
 *    created: 2022-03-29
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: dp[i] = weight for all subarrays that end at index i. Answer is sum of
// dp for all i from 0 -> n - 1. Have a PSA for each value that sums that indices
// that the values appeared up to the current index. dp[i] = dp[i - 1] + pref[a[i]] + 1
// (0-indexed). Why? dp[i - 1] so we can find the answer for all values that are
// not a[i]. pref[a[i]] + 1 so we can find the contribution of a[i] to the answer;
// we take the indices so gaps on the ends of them are counted.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    unordered_map<int, long long> pref;
    vector<long long> dp(n);
    dp[0] = 0;
    pref[a[0]] = 1;
    long long ans = 0;
    for (int i = 1; i < n; i++) {
      dp[i] = dp[i - 1] + pref[a[i]];
      ans += dp[i];
      pref[a[i]] += i + 1;
    }
    cout << ans << '\n';
  }
}
