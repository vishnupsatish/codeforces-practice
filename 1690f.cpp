/**
 *    author:  vishnus
 *    created: 2022-06-30
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: We can run an O(n^2) algorithm. The idea is as follows. We can model this as a possibly
// disconnected graph which consists of cycles. The answer is the LCM of when the characters of
// each cycle return to their original state. We can therefore just run an n^2 algorithm that
// determines in how many moves a cycle returns back to its original state. Key idea is LCM.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p(n);
    for (auto &e : p) {
      cin >> e;
      --e;
    }
    long long ans = 1;
    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
      if (vis[i]) {
        continue;
      }
      int cur_pos = p[i];
      vector<int> aff = {i};
      while (cur_pos != i) {
        aff.push_back(cur_pos);
        cur_pos = p[cur_pos];
        vis[cur_pos] = 1;
      }
      string cur = s;
      int cnt = 0;
      do {
        cnt++;
        string old_cur = cur;
        for (auto e : aff) {
          cur[e] = old_cur[p[e]];
        }
      } while (cur != s);
      ans = lcm(ans, (long long) cnt);
    }
    cout << ans << '\n';
  }
}
