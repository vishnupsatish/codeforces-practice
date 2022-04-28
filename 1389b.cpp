/**
 *    author:  vishnus
 *    created: 2022-04-27
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: it is always optimal to go left the maximum number of times at all i. Try all i,
// and try to go left for each i, then calculate the answer for that i. Why is it always
// optimal to go left the maximum number of times possible? Imagine we go left twice, then
// twice again later at a different index. If a[j] + a[j + 1] is greater for the second
// time we go left, it's better to just do all four left operations there, and vice-versa.
// All of the other elements stay the same. Also, we would always use up our 'z' quota,
// since imagine z = 4 and we only go left twice at some i value. It is always optimal
// to go left at the greatest a[i] + a[i - 1] value, which gets rid of a reduced such
// value.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n), pref(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pref[i + 1] = pref[i] + a[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) { // Make i the place we go right-left-right-left etc and try the rest (go left to i - 1)
      int cur = pref[i + 1];
      int curk = k - i;
      if (curk < 0) {
        break;
      }
      for (int j = 1; j <= z; j++) {
        if (curk == 0) {
          break;
        }
        cur += a[i - 1];
        curk--;
        if (curk == 0) {
          break;
        }
        cur += a[i];
        curk--;
      }
      if (curk != 0) {
        cur += pref[i + curk + 1] - pref[i + 1];
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
}
