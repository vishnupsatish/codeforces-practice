/**
*  author:  vishnus
*  created: 2022-09-01
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: important thing is note is that a consecutive group of ones cannot be removed, so we have to 
// match the first group of ones in 's' to the first group of ones in 't', and so on. Just simple math.

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
    string ss, ts;
    cin >> ss >> ts;
    vector<int> s(n), t(n);
    for (int i = 0; i < n; i++) {
      s[i] = ss[i] - '0';
      t[i] = ts[i] - '0';
    }
    if (s[0] != t[0] || s[n - 1] != t[n - 1]) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> sgrp(2), tgrp(2);
    int cur = s[0];
    for (int i = 1; i < n; i++) {
      if (s[i] != cur) {
        sgrp[cur]++;
        cur = s[i];
      }
    }
    sgrp[cur]++;
    cur = t[0];
    for (int i = 1; i < n; i++) {
      if (t[i] != cur) {
        tgrp[cur]++;
        cur = t[i];
      }
    }
    tgrp[cur]++;
    if (tgrp[0] != sgrp[0] || tgrp[1] != sgrp[1]) {
      cout << -1 << '\n';
      continue;
    }
    vector<pair<int, int>> ogs, ogt; // start index, end index
    cur = s[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      if (cur != s[i]) {
        if (cur == 1) {
          ogs.push_back({i - cnt + 1, i - 1});
        }
        cur = s[i];
        cnt = 1;
      } else {
        cnt++;
      }
    }
    if (cur == 1) {
      ogs.push_back({n - 1 - cnt + 1, n - 1});
    }
    cur = t[0];
    cnt = 1;
    for (int i = 1; i < n; i++) {
      if (cur != t[i]) {
        if (cur == 1) {
          ogt.push_back({i - cnt + 1, i - 1});
        }
        cur = t[i];
        cnt = 1;
      } else {
        cnt++;
      }
    }
    if (cur == 1) {
      ogt.push_back({n - 1 - cnt + 1, n - 1});
    }
    long long ans = 0;
    for (int i = 0; i < (int) ogs.size(); i++) {
      int st_s = ogs[i].first;
      int en_s = ogs[i].second;
      int st_t = ogt[i].first;
      int en_t = ogt[i].second;
      ans += abs(st_s - st_t);
      ans += abs(en_s - en_t);
    }
    cout << ans << '\n';
  }
}
