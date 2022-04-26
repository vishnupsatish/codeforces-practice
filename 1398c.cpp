/**
 *    author:  vishnus
 *    created: 2022-04-26
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: If we construct a PSA, the sum between l and r (inclusive) becomes
// p[r] - p[l - 1]. For the condition to be satisfied, p[r] - p[l - 1] ==
// r - (l - 1). We can rearrange this to p[r] - r == p[l - 1] - (l - 1),
// and store all occurrences of p[i] - i. Then, we can use handshake formula.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), pref(n + 1);
    string s;
    cin >> s;
    unordered_map<int, long long> cnt;
    for (int i = 0; i < n; i++) {
      a[i] = (int) (s[i] - '0');
      pref[i + 1] = pref[i] + a[i];
      cnt[pref[i + 1] - i - 1]++;
    }
    cnt[0]++;
    long long ans = 0;
    for (auto [k, v] : cnt) {
      ans += (v * (v - 1)) / 2;
    }
    cout << ans << '\n';
  }
}
