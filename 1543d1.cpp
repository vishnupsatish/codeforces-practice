/**
 *    author:  vishnus
 *    created: 2022-07-21
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/a/vFCgcdU

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
    auto Ask = [&](int y) {
      cout << y << endl;
      int r;
      cin >> r;
      return r;
    };
    if (Ask(0)) {
      continue;
    }
    for (int i = 2; i <= n; i++) {
      if (Ask((i - 1) ^ (i - 2))) {
        break;
      }
    }
  }
}
