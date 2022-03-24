/**
 *    author:  vishnus
 *    created: 2022-03-24
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: for y > x, the number y - (y % x) will be divisible by x. There is a
// point between y - (y % x) (which is the greatest number divisible by x that
// is not greater than y) and y such that the mods will be the same. That is
// the number between largest multiple of x less than of equal to y (b) and y (average
// of that value), which will be the answer, since the distance from the average to y
// and the distance from the average to b will be the same.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    int ans;
    if (x == y) {
      cout << (ans = x) << '\n';
    } else if (x > y) {
      cout << (ans = x + y) << '\n';
    } else {
      cout << (ans = y - (y % x) / 2) << '\n';
    }
    assert(ans % x == y % ans);
  }
}
