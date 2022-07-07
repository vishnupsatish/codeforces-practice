/**
 *    author:  vishnus
 *    created: 2022-07-06
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: two pointers. The key point with these problems is to go in order; 
// start at 0, then 1, 2, etc. Let p[x] be the position of the value 'x' in 'a'.
// 0 must be in p[0]. 1 must be in p[1]. Why? MEX of all subarrays that include
// 0 and 1 is at least 2, and everything else is 1. This condition is satisfied
// if the previous conditions are satisfied. Then, consider 2. If 2 lies between
// 0 and 1, then we know that regardless of where it is placed the subarray from
// 0 -> 1 will have a MEX value of 3 since 2 is between it. MEX of 2 -> 1 is 0,
// and MEX of 0 -> 2 is 1 so that has no impact. Therefore, we can multiply 
// r - l + 1 - 2 to the answer. Otherwise, say 2 lies before 0, then it must be
// placed at p[2] because subarrays that contain 0, 1, and 2 must have a value 
// of at least 3, and otherwise will be lower. The only way this is possible is
// if 2 is placed at p[2]. The same logic applies to every other number.

const int md = (int) 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> p(n); // Maps value to position. p[k] is the position of k in the array 'a'
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      p[a[i]] = i;
    }
    int l = p[0], r = p[1];
    if (l > r) {
      swap(l, r);
    }
    long long ans = 1;
    for (int i = 2; i < n; i++) {
      if (p[i] > l && p[i] < r) {
        ans *= (r - l + 1 - i);
        ans %= md;
      } else {
        l = min(l, p[i]);
        r = max(r, p[i]);
      }
    }
    cout << ans << '\n';
  }
}
