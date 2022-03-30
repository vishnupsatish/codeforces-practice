/**
 *    author:  vishnus
 *    created: 2022-03-30
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: utilize DP. dp[i] = length of string after performing i operations
// on 10. dp[i] = 2, 3, or dp[i - 9] + dp[i - 10]. Then calculate the answer
// for each digit in the string. Why does this work? The first digit is one
// ahead of the second, since 9 -> 10 -> 21, etc. After 9 operations, each digit
// will have doubled to two digits, except the digits that are zeroes. The digits
// that are zeroes will have been removed in the previous operations, so do
// dp[i - 9] + dp[i - 10].

const int md = (int) 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  const int mm = 200001;
  vector<long long> dp(mm + 1); // Length after performing i operations
  for (int i = 0; i < 9; i++) {
    dp[i] = 2;
  }
  dp[9] = 3;
  for (int i = 10; i <= mm; i++) {
    dp[i] = dp[i - 9] + dp[i - 10];
    dp[i] %= md;
  }
  while (tt--) {
    string n;
    int m;
    cin >> n >> m;
    long long ans = 0;
    for (auto &c : n) {
      int cv = (int) (c - '0');
      if (m + cv < 10) {
        ans++;
      } else {
        ans += dp[m - 10 + cv];
      }
      ans %= md;
    }
    cout << ans << '\n';
  }
}
