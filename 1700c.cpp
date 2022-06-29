/**
 *    author:  vishnus
 *    created: 2022-06-29
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: We will try to make the entire array equal to one number. We can do this by looping.
// If a number is less than the previous number, we have to set the entire prefix to the current
// number. Otherwise, we have to set the entire suffix to the previous number. Then, in the
// end, increase/decrease the entire array so that it becomes 0. We can do this by utilizing
// differences. Every time the current number is less than the previous number, the final
// number that the entire array will keep decreasing by that difference. Why is this optimal?
// Because increasing can only be done on the entire array, it doesn't make sense to do it any
// other time other than at the very beginning or the very end. Let's now try to set every
// element to one number, then. We can utilize the algorithm described previously.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    long long final = a[0];
    for (int i = 1; i < n; i++) {
      ans += abs(a[i] - a[i - 1]); // Absolute differences will always remain the same, regardless if we change a prefix or a suffix
      if (a[i] < a[i - 1]) {
        final -= a[i - 1] - a[i];
      }
    }
    cout << ans + abs(final) << '\n';
  }
}
