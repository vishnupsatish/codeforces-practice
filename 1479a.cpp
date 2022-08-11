/**
 *    author:  vishnus
 *    created: 2022-08-11
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: binary search. We only need to find one valley, so we can determine whether
// we are on a decreasing path or not. If we are on a decreasing path, we know that
// eventually on that path there will be a valley, so we only take the right side.
// Otherwise, take the left side since it is basically decreasing, but in the opposite direction.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int n;
  cin >> n;
  auto Query = [&](int Idx) {
    cout << "? " << Idx + 1 << endl;
    int val;
    cin >> val;
    return val;
  };
  int l = 0, r = n - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (Query(mid) < Query(mid + 1)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << "! " << l + 1 << '\n';
}
