/**
 *    author:  vishnus
 *    created: 2022-04-04
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Greedy. We want to make each painter paint something in order.
// Order: if b[i] != a[i] and c[i] == b[i], if b[i] == c[i], or if none
// of these are satisfied, make the painter paint something that is for
// sure going to be painter over in the future.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    unordered_map<int, int> cs;
    for (int i = 0; i < m; i++) {
      cin >> c[i];
      cs[c[i]]++;
    }
    unordered_map<int, unordered_set<int>> dif; // The ones that are different in that index
    unordered_map<int, unordered_set<int>> okval; // The ones that the same
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        dif[b[i]].insert(i);
      } else {
        okval[b[i]].insert(i);
      }
    }
    bool ok = true;
    for (auto &[k, v] : dif) {
      if (cs[k] < (int) v.size()) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    ok = false;
    int lst = c[m - 1];
    for (int i = 0; i < n; i++) {
      if (b[i] == lst) {
        ok = true;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    vector<int> ans(m, -1);
    vector<int> wrng;
    unordered_map<int, unordered_set<int>> ogdif = dif;
    for (int i = 0; i < m; i++) {
      int e = c[i];
      if (dif.contains(e)) {
        ans[i] = *dif[e].begin();
        dif[e].erase(*dif[e].begin());
        if (dif[e].empty()) {
          dif.erase(e);
        }
      } else {
        if (okval.contains(e)) {
          ans[i] = *okval[e].begin();
        } else if (ogdif.contains(e)) {
          ans[i] = *ogdif[e].begin();
        } else { // Here, we want to make the ith painter paint something which will for sure be painted over in the future to its correct paint.
          wrng.push_back(i);
        }
      }
    }
    for (auto e : wrng) {
      for (int i = e + 1; i < m; i++) {
        if (ans[i] != -1) {
          ans[e] = ans[i];
          break;
        }
      }
    }
    ok = true;
    for (int i = 0; i < m; i++) {
      if (ans[i] == -1) {
        ok = false;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < m; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << ans[i] + 1;
    }
    cout << '\n';
  }
}
