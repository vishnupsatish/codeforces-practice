/**
 *    author:  vishnus
 *    created: 2022-07-18
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if both n and m are even, then the number of horizontal and vertical dominoes must be even. 
// Why? An odd number of vertical dominoes, for example, means that two rows will have an odd number 
// of horizontal spots remaining, so you won't be able to place the remaining horizontal dominoes. 
// If n is odd and m is even (which we can make it be), we need to first place one row of solely 
// horizontal dominoes to be able to place vertical dominoes. And, the remianing horizontal dominoes
// must be placed as 2x2 squares to be able to place the remaining vertical dominoes. 

int main() {
  #ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (!(n & 1) && !(m & 1)) {
      cout << (!(k & 1) ? "YES" : "NO") << '\n';
      continue;
    }
    // Now we have one odd and one even
    // n should always be odd
    if (m & 1) {
      swap(n, m);
      k = (n * m) / 2 - k;
    }
    if (k >= m / 2 && !((k - m / 2) & 1)) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
