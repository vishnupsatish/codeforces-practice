/**
 *    author:  vishnus
 *    created: 2022-03-23
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: binary search for the answer.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    auto Do = [&](int val) -> bool {
      int to_have = val - 1;
      int have_done = 0;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (b[i] >= have_done && a[i] >= to_have) {
          have_done++;
          to_have--;
          cnt++;
        }
      }
      return cnt >= val;
    };
    int l = 0, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      if (Do(mid)) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    cout << (Do(l) ? l : l - 1) << '\n';
  }
  return 0;
}
