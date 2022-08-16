/**
 *    author:  vishnus
 *    created: 2022-08-16
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: adding 1 and subtracting 1 leads to a congruent sequence, so all we need to 
// know are the max and the min values in each prefix and suffix in the query. Prefix
// max/min is easy. For suffix max/min (taking the example of suffix max), we need to
// prepand an operation instead of append, so we do m[i] = max(0, m[i + 1] + a[i]) 
// since we have to add a[i] no matter what.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> o(n);
    vector<int> pref(n + 1);
    vector<int> pref_min(n + 1);
    vector<int> pref_max(n + 1);
    vector<int> suf_min(n + 1);
    vector<int> suf_max(n + 1);
    int cur = 0;
    for (int i = 0; i < n; i++) {
      char ops;
      cin >> ops;
      o[i] = (ops == '+' ? 1 : -1);
      cur += o[i];
      pref[i + 1] = pref[i] + o[i];
      pref_min[i + 1] = min(pref_min[i], cur);
      pref_max[i + 1] = max(pref_max[i], cur);
    }
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
      cur += o[i];
      suf_min[i] = min(0, o[i] + suf_min[i + 1]);
      suf_max[i] = max(0, o[i] + suf_max[i + 1]);
    }
    while (m--) {
      int l, r;
      cin >> l >> r;
      --l; --r;
      int min_val = min(pref_min[l], suf_min[r + 1] + pref[l]);
      int max_val = max(pref_max[l], suf_max[r + 1] + pref[l]);
      cout << max_val - min_val + 1 << '\n';
    }
  }
}
