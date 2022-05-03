/**
 *    author:  vishnus
 *    created: 2022-05-03
**/
#include <bits/stdc++.h>

using namespace std;

// Be greedy; we know that if a[i] != a[i - 1] then b[i] must be a[i - 1]. Otherwise, the MEX sequence would
// not match. If a[i] == a[i - 1], we can place the smallest number not in a and not already placed yet. This
// is the best thing to do greedily since if the smallest number not in a and not already placed yet is x,
// then x would have to be placed for a future value > x to be satisfied. We want to avoid repeating values,
// since we want to place the greatest values possible to make future 'a' values possible.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    int x;
    cin >> x;
    if (x != 0 && x != 1) {
      cout << -1 << '\n';
      return 0;
    }
    cout << !x << '\n';
    return 0;
  }
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] != 1 && a[0] != 0) {
    cout << -1 << '\n';
    return 0;
  }
  set<int> s;
  for (int i = 0; i <= 1e6; i++) {
    s.insert(i);
  }
  for (auto e : a) {
    s.erase(e);
  }
  for (int i = 0; i < n; i++) {
    if (i != 0 && a[i] != a[i - 1]) {
      b[i] = a[i - 1];
    } else {
      b[i] = *s.begin();
      s.erase(s.begin());
    }
  }
  set<int> chk;
  for (int i = 0; i <= 1e6; i++) {
    chk.insert(i);
  }
  for (int i = 0; i < n; i++) {
    if (chk.contains(b[i])) {
      chk.erase(b[i]);
    }
    if (*chk.begin() != a[i]) {
      cout << -1 << '\n';
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << b[i] << " \n"[i == n - 1];
  }
}
