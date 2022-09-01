/**
*  author:  vishnus
*  created: 2022-09-01
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: try to make a[i] the max element. Query for min prefix sum value from [pge, i - 1] and 
// max prefix sum value from [i, nge - 1] to find whether a[i] is the cause for a 'NO'.

#define int long long

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  int cnt = 0;
  while (tt--) {
    cnt++;
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &e : a) {
      cin >> e;
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    // cp-algos
    vector<int> lg(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
      lg[i] = lg[i/2] + 1;
    int k = ceil(log2(n));
    vector<vector<int>> st(n, vector<int>(k + 1));
    for (int i = 0; i < n; i++)
      st[i][0] = pref[i + 1];
    for (int j = 1; j <= k; j++)
      for (int i = 0; i + (1 << j) <= n; i++)
        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    auto RangeMin = [&](int L, int R) {
      int j = lg[R - L + 1];
      int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
      return minimum;
    };
    // cp-algos
    vector<vector<int>> stmax(n, vector<int>(k + 1));
    for (int i = 0; i < n; i++)
      stmax[i][0] = pref[i + 1];
    for (int j = 1; j <= k; j++)
      for (int i = 0; i + (1 << j) <= n; i++)
        stmax[i][j] = max(stmax[i][j-1], stmax[i + (1 << (j - 1))][j - 1]);
    auto RangeMax = [&](int L, int R) {
      int j = lg[R - L + 1];
      int maximum = max(stmax[L][j], stmax[R - (1 << j) + 1][j]);
      return maximum;
    };
    vector<int> nge(n, -1), pge(n, -1); // Next greater and previous greater elements
    stack<pair<int, int>> stk; // Value, index
    stk.push({a[0], 0});
    for (int i = 1; i < n; i++) {
      while (!stk.empty() && stk.top().first < a[i])  {
        nge[stk.top().second] = i;
        stk.pop();
      }
      stk.push({a[i], i});
    }
    while (!stk.empty()) {
      stk.pop();
    }
    stk.push({a[n - 1], n - 1});
    for (int i = n - 2; i >= 0; i--) {
      while (!stk.empty() && stk.top().first < a[i])  {
        pge[stk.top().second] = i;
        stk.pop();
      }
      stk.push({a[i], i});
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int lb = pge[i];
      if (lb == -1) {
        lb = -1;
      }
      int rb = nge[i];
      if (rb == -1) {
        rb = n;
      }
      int mx = RangeMax(i, rb - 1);
      int mn;
      if (i == 0) {
        mn = 0;
      } else if (lb == -1) {
        mn = min(RangeMin(0, i - 1), 0ll);
      } else {
        mn = RangeMin(lb, i - 1);
      }
      if (mx - mn > a[i]) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}
