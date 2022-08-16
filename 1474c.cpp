/**
 *    author:  vishnus
 *    created: 2022-08-16
**/
#include <bits/stdc++.h>

using namespace std;

const int mx = (int) 1e6;

// x can only decrease. So we pick the largest number + (loop for another number) as x, then brute force the rest. O(n^2).

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    unordered_map<int, int> tot_cnt;
    for (auto &e : a) {
      cin >> e;
      tot_cnt[e]++;
    }
    sort(a.begin(), a.end(), greater<>());
    bool done = false;
    for (int i = 1; i < n; i++) { // Try to start with 0 + i as x
      unordered_map<int, int> cnt; // Number of times we used the value 'i'
      cnt[a[i]] = 1;
      cnt[a[0]]++;
      vector<pair<int, int>> steps = {{a[0], a[i]}};
      int cur_x = a[0];
      bool ok = true;
      for (int j = 1; j < n; j++) {
        if (cnt[a[j]] == tot_cnt[a[j]]) {
          continue;
        }
        cnt[a[j]]++;
        if (tot_cnt[cur_x - a[j]] - cnt[cur_x - a[j]] == 0) {
          ok = false;
          break;
        }
        steps.push_back({a[j], cur_x - a[j]});
        cnt[cur_x - a[j]]++;
        cur_x = a[j];
      }
      if (!ok) {
        continue;
      }
      done = true;
      cout << "YES" << '\n';
      cout << steps[0].first + steps[0].second << '\n';
      for (auto [f, s] : steps) {
        cout << f << ' ' << s << '\n';
      }
      break;
    }
    if (!done) {
      cout << "NO" << '\n';
    }
  }
}
