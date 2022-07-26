/**
 *    author:  vishnus
 *    created: 2022-07-25
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: similar to casework. If sum is odd, can't partition. Then run 
// knapsack to see if it's possible. If it's not, answer is 0. Now, if
// the sum is divisible by 2, remove an odd number. If it's divisible 
// by 4, remove a number divisible by 2, etc. If all the numbers are 
// the same, remove something.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  int s = 0;
  for (auto &e : a) {
    cin >> e;
    s += e;
  }
  if (s & 1) {
    cout << 0 << '\n';
    return 0;
  }
  vector<int> dp(s / 2 + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int cs = s / 2; cs >= a[i]; cs--) {
      dp[cs] |= dp[cs - a[i]];
    }
  }
  if (!dp[s / 2]) {
    cout << 0 << '\n';
    return 0;
  }
  // if sum div. by 4, remove element that is not div. by 2, etc.
  for (int i = 4; i <= 2048; i *= 2) {
    for (int j = 0; j < n; j++) {
      if (a[j] % (i / 2) != 0) {
        cout << 1 << '\n' << j + 1 << '\n';
        return 0;
      }
    }
  }
  // All elements are the same
  cout << 1 << '\n' << 1 << '\n';
}
