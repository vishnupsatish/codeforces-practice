/**
 *    author:  vishnus
 *    created: 2022-07-25
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: we can break this down into subproblems of size n - 1, n - 2, and sum them together. 
// Why? Because we can leave that much area in the middle then run dp[whatever the remaining 
// space is]. If you want to make everything covered by the same size segments, we can pair 
// them d[n] - 1 times where d[n] is the number of divisors of n. 

const int md = 998244353;

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int n;
  cin >> n;
  vector<int> div(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      div[j]++;
    }
  }
  vector<long long> ans(n + 1);
  ans[0] = 1;
  ans[1] = 1;
  ans[2] = 3;
  long long pref = 4;
  for (int i = 3; i <= n; i++) {
    ans[i] = pref + div[i] - 1;
    ans[i] %= md;
    pref += ans[i];
    pref %= md;
  }
  cout << ans[n] << '\n';
}
