/**
*  author:  vishnus
*  created: 2022-08-22
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: it is optimal to place lower numbers as close as their corresponding '-' operation
// as possible because if we don't do that, then other '-' operations may mistakenly buy 
// things of a lower price. So we do that, then test.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int n;
  cin >> n;
  vector<pair<char, int>> a(2 * n);
  for (auto &[op, val] : a) {
    cin >> op;
    if (op == '-') {
      cin >> val;
    }
  }
  set<int> val;
  int cur = n - 1;
  for (int i = 2 * n - 1; i >= 0; i--) {
    if (a[i].first == '-') {
      val.insert(a[i].second);
    } else {
      if (val.empty()) {
        cout << "NO" << '\n';
        return 0;
      }
      a[i].second = *val.begin();
      val.erase(val.begin());
    }
  }
  if (!val.empty()) {
    cout << "NO" << '\n';
    return 0;
  }
  set<int> tst;
  vector<int> ans;
  for (int i = 0; i < 2 * n; i++) {
    if (a[i].first == '+') {
      tst.insert(a[i].second);
      ans.push_back(a[i].second);
    } else {
      if (tst.empty()) {
        cout << "NO" << '\n';
        return 0;
      }
      if (a[i].second != *tst.begin()) {
        cout << "NO" << '\n';
        return 0;
      }
      tst.erase(tst.begin());
    }
  }
  if ((int) ans.size() != n) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}
