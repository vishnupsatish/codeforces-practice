/**
 *    author:  vishnus
 *    created: 2022-03-28
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: binary search for the answer; determine how many single-priced
// and doubled-priced we need to buy for a certain price and greedily 
// buy double-priced and single-priced items to determine whether or 
// not it is possible.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  vector<pair<long long, long long>> av(n);
  long long s = 0;
  for (auto &[ca, cb] : av) {
    cin >> ca >> cb;
  }
  sort(av.begin(), av.end(), [] (auto f, auto s) { return f.second < s.second; });
  for (int i = 0; i < n; i++) {
    a[i] = av[i].first;
    b[i] = av[i].second;
    s += a[i];
  }
  auto Do = [&](long long val) -> bool {
    long long dp = val - s, sp = s - dp;
    long long dpcur = 0;
    long long spcur = 0;
    long long pr = 0;
    for (int i = n - 1; i >= 0; i++) {
      if (a[i] + dpcur >= dp) {
        dpcur = dp;
        break;
      }
      dpcur += a[i];
    }
    for (int i = 0; i < n; i++) {
      if (b[i] > dpcur + spcur) {
        return false;
      }
      if (spcur + a[i] >= sp) {
        break;
      }
      spcur += a[i];
    }
    return true;
  };
  long long l = s, r = 2 * s;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (Do(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << '\n';
}
