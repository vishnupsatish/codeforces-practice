/**
 *    author:  vishnus
 *    created: 2022-04-04
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Use the pigeonhole principle. Take the friend that appears the
// most amount of times (f). Sort the days based on how many friend
// choices each day has. Then, if a day has that f, then use f. Otherwise,
// leave it alone. When cnt[f] becomes too large, break. For all of the
// other ones that we didn't place it for, place something other than f.
// We must sort the days since if cnt[f] in total > the limit, then we
// may be forced to use f for something when we cannot use it (size = 1)
// and there is another optimal placement. Basically; when the there
// *little to no choice* in a day, place f. This works. Why? If cnt[f]
// in total >= lim, we will only place for lim and other floor(m/2) can
// be anything else. Else if cnt[f] in total < lim, since it is the largest,
// all of the other friends will appear in less days.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    int lim = m / 2 + (m & 1);
    vector<int> k(m);
    vector<pair<int, unordered_set<int>>> f(m);
    vector<pair<int, unordered_set<int>>> d(n);
    for (int i = 0; i < m; i++) {
      cin >> k[i];
      for (int j = 0; j < k[i]; j++) {
        int cf;
        cin >> cf;
        --cf;
        f[i].first = i;
        f[i].second.insert(cf);
        d[cf].first = cf;
        d[cf].second.insert(i);
      }
    }
    sort(f.begin(), f.end(), [](auto e1, auto e2) { return e1.second.size() < e2.second.size(); });
    sort(d.begin(), d.end(), [](auto e1, auto e2) { return e1.second.size() > e2.second.size(); });
    int fr = d[0].first;
    int frcnt = 0;
    vector<int> ans(m, -1);
    for (int i = 0; i < m; i++) {
      if (f[i].second.contains(fr)) {
        frcnt++;
        ans[f[i].first] = fr;
        if (frcnt == lim) {
          break;
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < m; i++) {
      if (ans[f[i].first] == -1) {
        if ((int) f[i].second.size() == 1 && f[i].second.contains(fr)) {
          cout << "NO" << '\n';
          ok = false;
          break;
        } else {
          for (auto &e : f[i].second) {
            if (e != fr) {
              ans[f[i].first] = e;
              break;
            }
          }
        }
      }
    }
    if (!ok) {
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
