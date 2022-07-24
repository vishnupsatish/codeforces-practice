/**
 *    author:  vishnus
 *    created: 2022-07-23
**/
#include <bits/stdc++.h>

using namespace std;

// Simple O(n^2) solution; loop from 0 to 3000 (the maximum value of a[i] for all 'i') and try 
// to make all of the cost values less than or equal to that value. When finding the greatest 
// floor quotient that is less than or equal to 'val', check if a[i] / floor(val) or a[i] / ceil(val)
// work.

int main() {
  #ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 1e9;
    for (int val = 0; val <= 3000; val++) { // Make all values as close as possible to, but less than or equal to val
      if (val == 0) {
        if (*max_element(a.begin(), a.end()) < k) {
          ans = 0;
          break;
        } else {
          continue;
        }
      }
      vector<int> cost(n);
      for (int i = 0; i < n; i++) {
        int ok_val = a[i] / (int) ceil((long double) a[i] / (long double) val);
        if (a[i] / val != 0) {
          int not_in_use = a[i] / (a[i] / val);
          if (not_in_use <= val) {
            swap(ok_val, not_in_use);
          }
        }
        cost[i] = max(a[i] / k, ok_val);
      }
      ans = min(ans, *max_element(cost.begin(), cost.end()) - *min_element(cost.begin(), cost.end()));
    }
    cout << ans << '\n';
  }
}
