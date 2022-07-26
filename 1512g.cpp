/**
 *    author:  vishnus
 *    created: 2022-07-25
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: precalculate sum of divisors for each number from 1 to 1e7
// using O(n log n) sieve. Then use arrays. Why is this 1700?

const int mx = (int) 1e7;

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  vector<int> div(mx + 1);
  for (int i = 1; i <= mx; i++) {
    for (int j = i; j <= mx; j += i) {
      div[j] += j / i;
    }
  }
  vector<int> ans(mx + 1, -1);
  for (int i = 1; i <= mx; i++) {
    if (div[i] <= mx && ans[div[i]] == -1) {
      ans[div[i]] = i;
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int c;
    cin >> c;
    cout << ans[c] << '\n';
  }
}
