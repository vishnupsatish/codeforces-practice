/**
 *    author:  vishnus
 *    created: 2022-05-13
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Brute force. Try to force i people to choose from the front, and the assume
// j people choose from the front from the ones you can't control. Answer will be the
// max of all i values (since you can control it), which will be the min of all the j
// values (since that cannot be controlled). It is optimal to control the first k
// people since you must determine the people being controlled before the process starts
// and changing this based on what happens after (random choice) is not allowed.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    k = min(k, m - 1);
    int ans = 0;
    int rem = m - k - 1;
    for (int i = 0; i <= k; i++) { // Take i elements from the start and k - i elements from the end, and find the minimum possible answer based on the arbitrary choices from the friends.
      int cur = 2e9;
      for (int j = 0; j <= rem; j++) { // The friends pick j elements at the front (after i elements from the front have been picked)
        cur = min(cur, max(a[i + j], a[i + j + n - m])); // When it's your turn, you can either choose the element at the front or the back of what's remaining
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
}
