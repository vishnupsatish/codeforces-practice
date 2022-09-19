/**
*  author:  vishnus
*  created: 2022-09-18
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: interval dp (that was pretty easy to figure out). State: dp[L][R]: who wins if the 
// string is from L -> R - 1. The key point is to combine Alice and Bob's move into one L, R
// combination, and to not separate them. This is because if it is a draw, both Alice's and
// Bob's characters chosen make an impact.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<vector<int>> dp(n, vector<int>(n, -2));
    function<int(int, int)> Solve = [&](int L, int R) { // R is exclusive
      if (L == R) {
        return 0;
      }
      if (dp[L][R - 1] != -2) {
        return dp[L][R - 1];
      }
      // Make Alice pick L
      int bv1 = 1;
      bv1 = min(bv1, Solve(L + 1, R - 1));
      if (Solve(L + 1, R - 1) == 0) {
        if (s[L] < s[R - 1]) {
          bv1 = 1;
        } else if (s[L] > s[R - 1]) {
          bv1 = max(bv1, -1);
        } else {
          bv1 = max(bv1, 0);
        }
      }
      bv1 = min(bv1, Solve(L + 2, R));
      if (Solve(L + 2, R) == 0) {
        if (s[L] < s[L + 1]) {
          bv1 = 1;
        } else if (s[L] > s[L + 1]) {
          bv1 = max(bv1, -1);
        } else {
          bv1 = max(bv1, 0);
        }
      }
      // Make Alice pick R
      int bv2 = 1;
      bv2 = min(bv2, Solve(L + 1, R - 1));
      if (Solve(L + 1, R - 1) == 0) {
        if (s[L] > s[R - 1]) {
          bv2 = 1;
        } else if (s[L] < s[R - 1]) {
          bv2 = max(bv2, -1);
        } else {
          bv2 = max(bv2, 0);
        }
      }
      bv2 = min(bv2, Solve(L, R - 2));
      if (Solve(L, R - 2) == 0) {
        if (s[R - 1] < s[R - 2]) {
          bv2 = 1;
        } else if (s[R - 1] > s[R - 2]) {
          bv2 = max(bv2, -1);
        } else {
          bv2 = max(bv2, 0);
        }
      }
      return dp[L][R - 1] = max(bv1, bv2);
    };
    Solve(0, n);
    if (dp[0][n - 1] == 1) {
      cout << "Alice" << '\n';
    } else if (dp[0][n - 1] == -1) {
      cout << "Bob" << '\n';
    } else {
      cout << "Draw" << '\n';
    }
  }
}
