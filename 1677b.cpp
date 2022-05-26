/**
 *    author:  vishnus
 *    created: 2022-05-26
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Kind of like dynamic programming, but based off simple modular arithmetic
// observations. Calculate the answer for each row and column separately. For each
// row, we know that after i + m new students entering, the positioning will be the
// same, except there might be a new student added (in the first row), so take that
// into account. For each column, each person moves cyclically to the right, so the
// answer cannot decrease. If the current person being added is serious and every
// student in the first column is naughty, then add one to the answer. Find the number
// of students in each column that are naughty by using a boolean array with the index
// being i % m.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> r(n * m), c(n * m);
    int ls = -1;
    vector<bool> md(m, true); // If all students in column mod m are naughty
    for (int i = 0; i < n * m; i++) {
      if (i > 0) {
        cout << ' ';
      }
      if (s[i] == '1') {
        ls = i;
      }
      int cr = 0, cc = 0;
      if (i >= m) {
        cr = r[i - m];
      }
      if (ls != -1 && i - ls < m) {
        cr++;
      }
      r[i] = cr;
      if (i > 0) {
        cc = c[i - 1];
      }
      if (s[i] == '1' && md[i % m]) {
        cc++;
        md[i % m] = false;
      }
      c[i] = cc;
      cout << cr + cc;
    }
    cout << '\n';
  }
}
