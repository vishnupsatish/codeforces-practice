/**
 *    author:  vishnus
 *    created: 2022-04-25
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if the max value of our sequence is ma, and min value is mi, any values between
// mi and ma are free insertions (no extra cost, since for example if there is 1, 7 and
// we want to insert 4, we can do 1, 4, 7 at no extra cost). So, just place 1 and x
// somewhere and all other insertions will be free. First, try to place 1 and x adjacent
// to each other. Then, try placing 1 before x. (Loop x position, place 1 at the best
// value before the current position). Then, do the same for x before 1.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i > 0) {
        ans += abs(a[i] - a[i - 1]);
      }
    }
    long long oans = ans;
    ans = oans + abs(x - 1) + abs(1 - a[0]);
    ans = min(ans, oans + abs(x - 1) + abs(x - a[0]));
    ans = min(ans, oans + abs(x - 1) + abs(x - a[n - 1]));
    ans = min(ans, oans + abs(x - 1) + abs(1 - a[n - 1]));
    for (int i = 1; i < n; i++) { // Place 1 and x before i
      ans = min(ans, oans - abs(a[i] - a[i - 1]) + abs(x - 1) + abs(x - a[i - 1]) + abs(1 - a[i]));
      ans = min(ans, oans - abs(a[i] - a[i - 1]) + abs(x - 1) + abs(1 - a[i - 1]) + abs(x - a[i]));
    }
    vector<int> pref(n + 1, 1e9); // Cost of placing 1 before i
    pref[0] = abs(1 - a[0]);
    for (int i = 0; i < n - 1; i++) { // Place x after i
      ans = min(ans, oans - abs(a[i] - a[i + 1]) + pref[i] + abs(a[i] - x) + abs(a[i + 1] - x));
      pref[i + 1] = min(pref[i], abs(1 - a[i]) + abs(1 - a[i + 1]) - abs(a[i + 1] - a[i]));
    }
    ans = min(ans, oans + pref[n - 1] + abs(a[n - 1] - x)); // Place x after n - 1
    pref.clear();
    reverse(a.begin(), a.end());
    pref[0] = abs(1 - a[0]);
    for (int i = 0; i < n - 1; i++) { // Place x after i
      ans = min(ans, oans - abs(a[i] - a[i + 1]) + pref[i] + abs(a[i] - x) + abs(a[i + 1] - x));
      pref[i + 1] = min(pref[i], abs(1 - a[i]) + abs(1 - a[i + 1]) - abs(a[i + 1] - a[i]));
    }
    ans = min(ans, oans + pref[n - 1] + abs(a[n - 1] - x));
    cout << ans << '\n';
  }
}
