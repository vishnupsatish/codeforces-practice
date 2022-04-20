/**
 *    author:  vishnus
 *    created: 2022-04-20
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Loop prefix. Find closest zero (since it is not optimal to have a zero in the
// prefix). Make that the suffix (or make the end the suffix if there are no more zeroes).
// Then, if the number of negative numbers in that range is odd, then we must find the 
// farthest negative in that range and make that position - 1 the new suffix. Then, 
// count the number of zeroes and maximize that.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> neg(n + 1), pos(n + 1), zero(n + 1), two(n + 1);
    vector<int> neg_pos;
    unordered_map<int, vector<int>> zvals;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      neg[i + 1] = neg[i] + (a[i] < 0);
      pos[i + 1] = pos[i] + (a[i] > 0);
      zero[i + 1] = zero[i] + (a[i] == 0);
      two[i + 1] = two[i] + (abs(a[i]) == 2);
      zvals[zero[i + 1]].push_back(i);
      if (a[i] < 0) {
        neg_pos.push_back(i);
      }
    }
    int twos = 0;
    int pfx = 0, sfx = n;
    for (int i = 0; i < n; i++) { // Start prefix at i
      if (a[i] == 0) {
        continue;
      }
      int suf;
      if (!zvals[zero[i] + 1].empty()) {
        suf = zvals[zero[i] + 1][0] - 1;
      } else {
        suf = n - 1;
      }
      if (i > suf) {
        continue;
      }
      if ((neg[suf + 1] - neg[i]) & 1) { // we need to binary search for the farthest negative then remove that
        int idx = (int) (upper_bound(neg_pos.begin(), neg_pos.end(), suf) - neg_pos.begin() - 1);
        if (idx < 0) {
          continue;
        }
        idx = neg_pos[idx] - 1;
        if (idx < i) {
          continue;
        }
        suf = idx;
      }
      if (two[suf + 1] - two[i] > twos) {
        twos = two[suf + 1] - two[i];
        pfx = i;
        sfx = n - 1 - suf;
      }
    }
    cout << pfx << ' ' << sfx << '\n';
  }
}
