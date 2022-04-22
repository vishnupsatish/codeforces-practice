/**
 *    author:  vishnus
 *    created: 2022-04-22
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: x can only increase and a[i] can only decrease when swapped. Therefore, 
// a greedy method works. Until a is sorted, we should find the first position 
// from the left that can be swapped with x. Why do we do this? If we swapped 
// something *after* the first position that can be swapped, that number would 
// become less than a[i] and would make it not relatively sorted, if it was, 
// originally. There is no point of doing so. If you cannot do anything and a 
// is not sorted, then just print -1 since you cannot sort it.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    while (!is_sorted(a.begin(), a.end())) {
      bool ok = false;
      for (int i = 0; i < n - 1; i++) {
        if (x < a[i]) {
          swap(x, a[i]);
          ok = true;
          break;
        }
      }
      ans++;
      if (!ok) {
        ans = -1;
        break;
      }
    }
    cout << ans << '\n';
  }
}
