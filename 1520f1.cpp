/**
 *    author:  vishnus
 *    created: 2022-03-29
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: binary search. Check l -> mid, if there is less zeroes, the subtract
// k by the number of zeroes in l -> mid and explore mid -> r. Else, explore l -> mid.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, t, k;
  cin >> n >> t >> k;
  auto Ask = [](int l, int r) -> int {
    cout << "? " << l << ' ' << r << endl;
    int x;
    cin >> x;
    return x;
  };
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    int val = Ask(l, mid);
    if (val + k <= (mid - l + 1)) {
      r = mid;
    } else {
      k -= ((mid - l + 1) - val);
      l = mid + 1;
    }
  }
  cout << "! " << l << endl;
}
