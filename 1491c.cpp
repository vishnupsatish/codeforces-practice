/**
 *    author:  vishnus
 *    created: 2022-08-04
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: pretty smart solution. The optimal idea is to go to the earliest s[i] value that
// is not 1. So, when we go to an s[i] value, we want to make it 1. This means that in those
// passes we will go to s[i + 1] all the way to s[i + s[i]]. Instead of simulating those 
// passes immediately, we can simulate them as part of our main loop. Track how many times 
// we go to s[j] as part of a prior pass. Let that be pp[j]. ans += max(0, s[j] - pp[j]) 
// since we need to start that many passes from 'j'. If pp[j] > s[j], add the remaining to
// pp[j + 1] since we pass through 'j' when s[j] is 1 some times, going to the next element.

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
    long long ans = 0;
    vector<long long> auto_go(n + 1);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < min(n, i + a[i] + 1); j++) {
        auto_go[j]++;
      }
      ans += max(0ll, a[i] - auto_go[i]);
      auto_go[i + 1] += max(0ll, auto_go[i] - a[i]);
    }
    cout << ans - 1 << '\n';
  }
}
