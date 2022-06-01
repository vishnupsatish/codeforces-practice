/**
 *    author:  vishnus
 *    created: 2022-06-01
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: When MEX comes up, the problem's idea is most likely to be greedy. If the MEX
// value is greater than the current i, just increment all occurrences of i by one to
// make the MEX value equal to i. If the MEX value is less, we have to increment all
// of the occurrences of i and we have to take all of the missing numbers (that were
// not in 'a') that were less than i, and increment some of the duplicates in 'a' to
// become the missing numbers. We can use a set to implement and we can also carry over
// the number of duplicates we need to increment to subsequent values of i. For example,
// if our duplicates are 3 and 4 and we are missing 7, we can make the 4 -> 7 using 3
// operations, then if we end up missing a 9 after, we can make the 3 -> 9 using 6 operations,
// which is a total of 9 operations due to missing numbers.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> cnt;
    set<int> mx;
    for (int i = 0; i < n + 1; i++) {
      mx.insert(i);
    }
    for (auto &e : a) {
      cin >> e;
      cnt[e]++;
      mx.erase(e);
    }
    multiset<int> duplicates;
    for (auto [k, v] : cnt) {
      for (int i = 0; i < v - 1; i++) {
        duplicates.insert(k);
      }
    }
    int mex = *mx.begin();
    vector<long long> ans(n + 1, -1);
    set<int, greater<>> missing; // What do we need to make some of the duplicate elements into?
    long long dup_cnt = 0;
    vector<int> vis(n + 1);
    for (int i = 0; i < n + 1; i++) {
      if (!missing.empty()) {
        int fmissing = *missing.begin();
        if (!vis[fmissing]) {
          vis[fmissing] = 1;
          if (duplicates.empty()) {
            break;
          }
          if (*duplicates.begin() > fmissing) {
            break;
          }
          int fdup = *--duplicates.upper_bound(fmissing);
          dup_cnt += fmissing - fdup;
          duplicates.erase(duplicates.find(fdup));
        }
      }
      int cur_cnt = cnt.contains(i) ? cnt[i] : 0;
      if (mex >= i) {
        ans[i] = cur_cnt;
      } else {
        ans[i] = cur_cnt + dup_cnt;
      }
      if (mx.contains(i)) {
        missing.insert(i);
      }
    }
    for (int i = 0; i < n + 1; i++) {
      cout << ans[i] << " \n"[i == n];
    }
  }
}
