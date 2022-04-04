/**
 *    author:  vishnus
 *    created: 2022-04-04
**/
#include <bits/stdc++.h>

using namespace std;

// Use binary search. Query L -> R. If the second max is in the range L -> Mid, 
// then check if L -> Mid == L -> R. If so, then our answer is within the range 
// L -> Mid. The same applies to Mid + 1 -> R.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto Ask = [](int L, int R) -> int {
    if (L >= R) {
      return -1;
    }
    cout << "? " << L + 1 << ' ' << R + 1 << endl;
    int x;
    cin >> x;
    --x;
    return x;
  };
  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    int lr = Ask(l, r - 1);
    if (lr < mid) {
      if (Ask(l, mid - 1) == lr) {
        r = mid;
      } else {
        l = mid;
      }
    } else {
      if (Ask(mid, r - 1) == lr) {
        l = mid;
      } else {
        r = mid;
      }
    }
  }
  cout << "! " << l + 1 << endl;
}
