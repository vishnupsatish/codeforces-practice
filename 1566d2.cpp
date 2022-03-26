/**
 *    author:  vishnus
 *    created: 2022-03-25
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if sight values are the same, they can occupy a range of seat values.
// They can occupy prefixes, full, suffixes, and parts. Greedily assign to suffixes
// first (since we'll go through less in the future), then fulls, then prefixes
// (so we go through less and will obstruct less), then parts.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m), s(n * m);
    for (int i = 0; i < n * m; i++) {
      cin >> a[i];
      s[i] = a[i];
    }
    sort(s.begin(), s.end());
    unordered_map<int, vector<int>> ns;
    for (int i = 0; i < n * m; i++) {
      ns[s[i]].push_back(i);
    }
    unordered_map<int, vector<int>> full;
    unordered_map<int, tuple<int, int, int>> suffix;
    unordered_map<int, tuple<int, int, int>> prefix;
    unordered_map<int, tuple<int, int, int>> part;
    for (auto &[num, vals] : ns) {
      int fst = vals[0];
      int lst = vals[(int) vals.size() - 1];
      if (lst - fst + 1 < m && fst % m <= lst % m && (lst + 1) % m != 0 && fst % m != 0) {
        part[num] = {fst / m, fst % m, lst % m};
      } else {
        for (int i = fst; i <= lst;) {
          if (i % m != 0) {
            suffix[num] = {i / m, i % m, m - 1};
            i = m * (i / m + 1);
          } else if (i + m - 1 <= lst) {
            full[num].push_back(m);
            i += m;
          } else {
            prefix[num] = {i / m, 0, lst - i};
            i = lst + 1;
          }
        }
      }
    }
    int inc = 0;
    vector<vector<int>> plc(n, vector<int>(m));
    for (int i = 0; i < n * m; i++) {
      if (suffix.contains(a[i])) {
        int row = get<0>(suffix[a[i]]), start = get<1>(suffix[a[i]]), &end = get<2>(suffix[a[i]]);
        for (int j = 0; j <= end; j++) {
          inc += plc[row][j];
        }
        plc[row][end] = 1;
        end--;
        if (end < start) {
          suffix.erase(a[i]);
        }
      } else if (full.contains(a[i])) {
        full[a[i]].back()--;
        if (full[a[i]].back() <= 0) {
          full[a[i]].pop_back();
        }
        if (full[a[i]].empty()) {
          full.erase(a[i]);
        }
      } else if (prefix.contains(a[i])) {
        int row = get<0>(prefix[a[i]]), start = get<1>(prefix[a[i]]), &end = get<2>(prefix[a[i]]);
        plc[row][end] = 1;
        end--;
        if (end < start) {
          suffix.erase(a[i]);
        }
      } else if (part.contains(a[i])) {
        int row = get<0>(part[a[i]]), start = get<1>(part[a[i]]), &end = get<2>(part[a[i]]);
        for (int j = 0; j <= end; j++) {
          inc += plc[row][j];
        }
        plc[row][end]++;
        end--;
        if (end < start) {
          part.erase(a[i]);
        }
      }
    }
    cout << inc << '\n';
  }
}
