/**
 *    author:  vishnus
 *    created: 2022-04-28
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: DP works; not greedy since if we reverse a subarray, we cannot reverse any more. 
// dp[i][j][k] = the best answer at index i when the sequence is done (j == 1) and when 
// we are currently in a sequence (k == i). Fairly simple transition; two different DPs 
// must be run. For the first DP, when we start a sequence (at an odd index), we make the
// subarray that we want to reverse start at i - 1 (and end at i - 1, basically i). For 
// the second DP, we make it start at i + 1 (and end at i + 1). If we start at i - 1, 
// then we need to take the dp value at i - 3 since i - 1 was reversed and therefore became
// an odd position (was originally even). If we start at i + 1, we need to take the dp 
// value at i - 1 but when we end (at an even index) we need to take the DP value at i - 3
// since i - 1 would not have been in the sequence.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n == 1) {
      int x;
      cin >> x;
      cout << x << '\n';
      continue;
    } else if (n == 2) {
      int x, _;
      cin >> x >> _;
      cout << max(x, _) << '\n';
      continue;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    { // First try to start the subarray at i - 1
      vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(2, vector<long long>(2))); // i: index, 1: done, 0: not done, 1: in sequence, 0: not in sequence
      dp[0][0][0] = a[0];
      ans = max(ans, dp[0][0][0]);
      dp[1][0][1] = a[1];
      ans = max(ans, dp[1][0][1]);
      dp[2][0][0] = a[0] + a[2];
      ans = max(ans, dp[2][0][0]);
      dp[2][1][0] = max(dp[1][0][1], dp[0][1][0]) + a[2];
      ans = max(ans, dp[2][1][0]);
      for (int i = 3; i < n; i++) {
        if (i & 1) {
          dp[i][0][1] = max(dp[i - 3][0][0], dp[i - 2][0][1]) + a[i];
        } else {
          dp[i][0][0] = dp[i - 2][0][0] + a[i];
          dp[i][1][0] = max(dp[i - 1][0][1], dp[i - 2][1][0]) + a[i];
        }
        ans = max(ans, dp[i][0][0]);
        ans = max(ans, dp[i][0][1]);
        ans = max(ans, dp[i][1][0]);
      }
    }
    { // Try to start subarray at i + 1
      vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(2, vector<long long>(2))); // i: index, 1: done, 0: not done, 1: in sequence, 0: not in sequence
      dp[0][0][0] = a[0];
      ans = max(ans, dp[0][0][0]);
      dp[1][0][1] = a[0] + a[1];
      ans = max(ans, dp[1][0][1]);
      dp[2][0][0] = a[0] + a[2];
      ans = max(ans, dp[2][0][0]);
      for (int i = 3; i < n; i++) {
        if (i & 1) {
          if (i < n - 1) {
            dp[i][0][1] = max(dp[i - 1][0][0], dp[i - 2][0][1]) + a[i];
          }
        } else {
          dp[i][0][0] = dp[i - 2][0][0] + a[i];
          dp[i][1][0] = max(dp[i - 3][0][1], dp[i - 2][1][0]) + a[i];
        }
        ans = max(ans, dp[i][0][0]);
        ans = max(ans, dp[i][0][1]);
        ans = max(ans, dp[i][1][0]);
      }
    }
    cout << ans << '\n';
  }
}
