/**
*  author:  vishnus
*  created: 2022-09-07
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: this problem is slightly easier because we have to find the number of numbers that are
// strictly less than 2^p. For every given number, there will be one number 'v' that satisfies
// 2^k <= 'v' < 2^(k + 1), since x2+1 increases the length of the binary sequence by exactly 1,
// and x4 increases the length of the binary sequence by 2. Find the number of "useless" numbers
// and do DP based on that.

const int md = (int) 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p;
  cin >> n >> p;
  set<int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.insert(x);
  }
  // Find all "useful" numbers; for each 'e' determine if e's parent exists in the set
  unordered_set<int> vals;
  for (auto e : a) {
    int cur = e;
    bool ok = true;
    while (cur > 1) {
      if (cur % 4 == 0) {
        cur /= 4;
      } else if (cur & 1) {
        cur = (cur - 1) / 2;
      } else {
        break;
      }
      if (vals.contains(cur)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      vals.insert(e);
    }
  }
  unordered_map<int, int> p2v;
  for (auto e : vals) {
    int fnd = floor(log2(e) + 1);
    p2v[fnd]++;
  }
  vector<int> dp(p + 1);
  long long ans = 0;
  for (int i = 0; i < p + 1; i++) {
    if (p2v.contains(i)) {
      dp[i] += p2v[i];
    }
    if (i >= 1) {
      dp[i] += dp[i - 1];
    }
    if (i >= 2) {
      dp[i] += dp[i - 2];
    }
    dp[i] %= md;
    ans += dp[i];
    ans %= md;
  }
  cout << ans << '\n';
}
