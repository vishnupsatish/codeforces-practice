/**
 *    author:  vishnus
 *    created: 2022-04-14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> c(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (b[i] < a[i]) {
        swap(a[i], b[i]);
      }
    }
    vector<vector<long long>> dp(n, vector<long long>(2)); // 0: continue. 1: end the cycle there. If dp[i][k] == -1, you cannot continue/end the cycle from/at that chain
    dp[0][0] = (c[0] - b[1] + 1) + a[1];
    for (int i = 1; i < n; i++) {
      if (b[i] == a[i]) { // Need to start a new one
        dp[i][0] = (c[i] - b[i + 1] + 1) + (a[i + 1]);
        dp[i][1] = (c[i]);
      } else {
        if (b[i + 1] != a[i + 1]) {
          dp[i][0] = dp[i - 1][0] + (c[i] - b[i + 1] + 1) + (a[i + 1]);
        } else {
          dp[i][0] = -1;
        }
        dp[i][1] = dp[i - 1][0] + (c[i]);
      }
    }
    vector<long long> suf(n + 1);
    for (int i = n - 1; i >= 0; i--) {
      if (a[i + 1] != b[i + 1]) {
        suf[i] = max(suf[i + 1], dp[i][1]);
      } else {
        suf[i] = dp[i][1];
      }
    }
    long long ans = 0;
    long long red = 0;
    for (int i = 0; i < n - 1; i++) { // Try to begin at i.
      if (a[i + 1] == b[i + 1]) {
        red = 0;
        ans = max(ans, suf[i + 1] + 1);
      } else {
        red += (c[i] - b[i + 1] + 1) + a[i + 1];
        ans = max(ans, suf[i + 1] - red + (b[i + 1] - a[i + 1] + 1));
      }
    }
    cout << ans << '\n';
  }
}
