/**
 *    author:  vishnus
 *    created: 2022-04-03
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: this problem can be solved using only the last three elements. First
// set everything else to 1. Last three elements will be a, b, c, and the sum
// to set to now is s = n - k + 3 since the LCM of all the 1s is just 1. if s
// is odd, set a = s / 2, b = s / 2, c = 1. If s is even but not a multiple of
// 4, set a = s / 2 - 1, b = s / 2 - 1, c = 2. This works because a and b are
// guaranteed to be even when you do s / 2 - 1. If s is a multiple of 4, do s
// / 2, s / 4, s / 4.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(k, 1);
    int s = n - k + 3;
    if (s & 1) {
      a[0] = a[1] = s / 2;
      a[2] = 1;
    } else if (s % 4 != 0) {
      a[0] = a[1] = s / 2 - 1;
      a[2] = 2;
    } else {
      a[0] = a[1] = s / 4;
      a[2] = s / 2;
    }
    for (int i = 0; i < k; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << a[i];
    }
    cout << '\n';
  }
}
