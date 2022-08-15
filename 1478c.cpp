/**
 *    author:  vishnus
 *    created: 2022-08-14
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: we know that 0 cannot exist. Consider 'a'. d[i] = 2 * a[j] for j such 
// that a[j] is larger than a[i] + 2 * a[i] * (number of elements that are 
// smaller than a[i]). This is a pattern. We can calculate answer based on this.

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
    vector<long long> d(2 * n);
    for (auto &e : d) {
      cin >> e;
    }
    unordered_map<long long, int> cnt;
    for (auto &e : d) {
      cnt[e]++;
    }
    bool ok = true;
    for (auto [k, v] : cnt) {
      if (v != 2 || k & 1) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = (*cnt.begin()).first / 2;
      cnt.erase(cnt.begin());
    }
    sort(a.begin(), a.end(), greater<>());
    long long pref = 0;
    for (int i = 0; i < n; i++) {
      if ((a[i] - pref) / (n - i) <= 0) {
        ok = false;
        break;
      }
      if ((a[i] - pref) % (n - i) != 0) {
        ok = false;
        break;
      }
      pref += (a[i] - pref) / (n - i);
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
  }
}
