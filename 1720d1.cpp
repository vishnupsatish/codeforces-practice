/**
*  author:  vishnus
*  created: 2022-08-30
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/a/yu8wVy9

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) {
      cin >> e;
    }
    vector<int> dp(n); // max. length of subsequence that ends at i
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
      for (int j = i; j >= max(0, i - 256); j--) {
        if ((a[j] ^ i) < (a[i] ^ j)) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      dp[i] = max(dp[i], 1);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
}
