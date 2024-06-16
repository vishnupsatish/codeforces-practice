#include <bits/stdc++.h>

using namespace std;

// Editorial NOT used
// Idea: modified knapsack; index on value and store the min weight needed to 
// reach that value. Except, we should only apply the transition if new weight
// is <= x * i (the cumulative money up to this point). Loop both happiness 
// and backwards on the items to get the optimal previous item that reduces 
// the weight needed.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int m;
    long long x;
    cin >> m >> x;
    vector<int> c(m), h(m);
    int maxh = 0;
    for (int i = 0; i < m; i++) {
      cin >> c[i] >> h[i];
      maxh += h[i];
    }
    vector<vector<long long>> dp(m, vector<long long>(maxh + 1, 1e18));
    dp[0][h[0]] = c[0] == 0 ? 0 : 1e18;
    for (int i = h[0] - 1; i >= 0; i--) {
      dp[0][i] = dp[0][i + 1];
    }
    for (int i = 1; i < m; i++) {
      if (c[i] <= x * i) {
        dp[i][h[i]] = c[i];
      }
      for (int hap = maxh; hap >= h[i]; hap--) {
        for (int j = i - 1; j >= 0; j--) {
          if (dp[j][hap - h[i]] == 1e18 || dp[j][hap - h[i]] + c[i] > x * i) {
            continue;
          }
          dp[i][hap] = min(dp[i][hap], dp[j][hap - h[i]] + c[i]);
        }
        if (hap != maxh) {
          dp[i][hap] = min(dp[i][hap], dp[i][hap + 1]);
        }
      }
    }
    int max_hap = 0;
    for (int i = 0; i < m; i++) {
      for (int hap = 0; hap <= maxh; hap++) {
        if (dp[i][hap] != 1e18) {
          max_hap = max(max_hap, hap);
        }
      }
    }
    cout << max_hap << '\n';
  }
}
