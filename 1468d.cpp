/**
 *    author:  vishnus
 *    created: 2022-08-17
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: the optimal thing to do is first release firecrackers, then run. Binary search
// for the answer. When checking, we need to release the largest firecrackers first then
// go in descending order. We can basically check whether s[i] < time remaining (which is
// just total_rem - i).

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> s(m);
    for (auto &e : s) {
      cin >> e;
    }
    sort(s.begin(), s.end());
    int frcs;
    int tot_s;
    if (a < b) {
      frcs = b - a - 1;
      tot_s = b - 1;
    } else {
      frcs = a - b - 1;
      tot_s = n - b;
    }
    auto Check = [&](int val) {
      int cnt = 1;
      bool ok = true;
      for (int i = val; i >= 0; i--) {
        if (s[i] + cnt++ > tot_s) {
          ok = false;
          break;
        }
      }
      return ok;
    };
    // Binary search for the answer
    int l = 0, r = min(m - 1, frcs - 1);
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (!Check(mid)) {
        r = mid - 1;
      } else {
        ans = mid;
        l = mid + 1;
      }
    }
    cout << ans + 1 << '\n';
  }
}
