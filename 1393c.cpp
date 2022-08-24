/**
*  author:  vishnus
*  created: 2022-08-24
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: binary search for the answer since we know that if a space of n works, a space of 
// n - 1 will work. To check, we can use a greedy algorithm that loops from 0 to n - 1, and
// at a given spot places a possible element with the most occurrences. If no such element
// exists, we return false. Why doesn't the strategy of placing the most frequent elements
// fully first, then second next, etc. work? Because we are not doing what is optimal at 
// every move. We may be placing something with less occurrences remaining than another one,
// at a current spot, leading to something suboptimal.

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
    vector<int> a(n);
    for (auto &e : a) {
      cin >> e;
    }
    unordered_map<int, int> cur_cnt;
    set<pair<int, int>, greater<>> vals;
    for (auto e : a) {
      cur_cnt[e]++;
      if (vals.contains({cur_cnt[e] - 1, e})) {
        vals.erase({cur_cnt[e] - 1, e});
      }
      vals.insert({cur_cnt[e], e});
    }
    int l = 0, r = n;
    int ans = -1;
    auto Check = [&](int spc) -> bool {
      unordered_map<int, int> cant_use;
      set<pair<int, int>, greater<>> cvals = vals;
      vector<int> arr(n);
      for (int i = 0; i < n; i++) {
        if (cvals.empty()) {
          return false;
        }
        arr[i] = (*cvals.begin()).second;
        cant_use[(*cvals.begin()).second] = (*cvals.begin()).first;
        cvals.erase(cvals.begin());
        if (i >= spc) {
          if (cant_use[arr[i - spc]] >= 2) {
            cvals.insert({cant_use[arr[i - spc]] - 1, arr[i - spc]});
            cant_use.erase(arr[i - spc]);
          }
        }
      }
      return true;
    };
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (Check(mid)) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    cout << ans << '\n';
  }
}
