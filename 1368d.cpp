/**
*  author:  vishnus
*  created: 2022-08-27
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/a/4BTMsD3

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> ans(n);
  for (int bit = 19; bit >= 0; bit--) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += ((a[i] & (1 << bit)) > 0);
    }
    for (int i = 0; i < cnt; i++) {
      ans[i] |= 1 << bit;
    }
  }
  long long val = 0;
  for (auto e : ans) {
    val += e * e;
  }
  cout << val << '\n';
}
