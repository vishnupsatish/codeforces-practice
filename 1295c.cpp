/**
 *    author:  vishnus
 *    created: 2022-05-13
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: be greedy; we basically want to form substrings out of subsequences of 
// string s to make string t. Answer is -1 if a character is in string t but not
// in s. Then, we can utilize the greedy algorithm. Store all indices of each 
// character that appears in string s (then keep that sorted). Then, loop t. 
// For the first character choose the first index in string s. Then, choose the
// least index that is greater than the current index, then set that to the current
// index. Since the goal is to minimize the number of operations, we don't want 
// to start a new operation (choosing an index *after* the current index) and we
// want to allow for more operations (so we choose the least index after the 
// current index, and not the greatest, for example). When there are no indices
// that are greater than the current index, we can start a new operation at the 
// current character in t and choose the first occurrence in s, then continue the cycle.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    int n = (int) s.size();
    int m = (int) t.size();
    unordered_map<char, bool> sc;
    for (auto e : t) {
      sc[e] = false;
    }
    for (auto e : s) {
      sc[e] = true;
    }
    bool ok = true;
    for (auto [k, v] : sc) {
      if (!v) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    unordered_map<char, vector<int>> idx; // Maps characters to their respective indices in string s
    for (int i = 0; i < n; i++) {
      idx[s[i]].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < m;) {
      int cur = idx[t[i]][0];
      i++;
      for (; i < m; i++) {
        if (idx[t[i]].back() <= cur) {
          break;
        }
        int nind = upper_bound(idx[t[i]].begin(), idx[t[i]].end(), cur) - idx[t[i]].begin();
        cur = idx[t[i]][nind];
      }
      ans++;
    }
    cout << ans << '\n';
  }
}
