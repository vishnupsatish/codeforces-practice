/**
 *    author:  vishnus
 *    created: 2022-07-13
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/a/lwxvfIc

int main() {
  #ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif
  int n, m;
  cin >> n >> m;
  vector<long long> dp(n + 1);
  dp[n] = 1;
  long long rpsa = 0;
  for (int i = n; i >= 1; i--) {
    dp[i] += rpsa;
    vector<int> done((int) sqrt(i) + 1);
    for (int j = 2; j <= sqrt(i); j++) {
      dp[i / j] += dp[i];
      dp[i / j] %= m;
      if (i / j <= (int) sqrt(i)) {
        done[i / j] = 1;
      }
    }
    for (int j = 1; j < sqrt(i); j++) {
      if (!done[j]) {
        dp[j] += dp[i] * ((i / j) - (i / (j + 1)));
        dp[j] %= m;
      }
    }
    dp[i] %= m;
    rpsa += dp[i];
    rpsa %= m;
  }
  cout << dp[1] << '\n';
}
