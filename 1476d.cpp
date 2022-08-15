/**
 *    author:  vishnus
 *    created: 2022-08-15
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: we can use DP to solve the problem. The optimal idea is to go as left as possible 
// from a certain city then go as right as possible from the starting node. Why? If we go
// left any amount of times, it is guaranteed that we are able to right back to the starting 
// point, simple parity stuff. Then we should just go right from there. Simple, can be done 
// using DP (my impl. probably has too many states, some are unwanted).

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
    vector<int> dir(n); // 0: left. 1: right.
    for (auto &e : dir) {
      char cur;
      cin >> cur;
      e = (cur == 'R');
    }
    // dp[i][j][k]: max number of unique cities for road i such that (j == 0: roads are original
    // direction, j == 1: roads are opposite direction) and (k == 0: going left, k == 1: going right).
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2)));
    vector<vector<vector<int>>> vis(n + 1, vector<vector<int>>(2, vector<int>(2)));
    function<int(int, int, int)> Solve = [&](int cur, int opp, int cur_dir) { // cur_dir is 0: left, 1: right
      if (vis[cur][opp][cur_dir]) {
        return dp[cur][opp][cur_dir];
      }
      vis[cur][opp][cur_dir] = 1;
      // Conditions for not being able to proceed
      if ((cur == 0 && cur_dir == 0) || (cur == n && cur_dir == 1)) {
        return dp[cur][opp][cur_dir] = 1;
      }
      if (cur_dir == 0 && (dir[cur - 1] ^ opp) == 1) { // Cannot go left
        return dp[cur][opp][cur_dir] = 1;
      }
      if (cur_dir == 1 && (dir[cur] ^ opp) == 0) { // Cannot go right
        return dp[cur][opp][cur_dir] = 1;
      }
      if (cur_dir == 0) {
        return dp[cur][opp][cur_dir] = 1 + Solve(cur - 1, !opp, cur_dir);
      } else {
        return dp[cur][opp][cur_dir] = 1 + Solve(cur + 1, !opp, cur_dir);
      }
    };
    for (int i = 0; i < n + 1; i++) {
      if (!vis[i][0][0]) {
        Solve(i, 0, 0);
      }
      if (!vis[i][0][1]) {
        Solve(i, 0, 1);
      }
      cout << dp[i][0][0] + dp[i][0][1] - 1 << " \n"[i == n];
    }
  }
}
