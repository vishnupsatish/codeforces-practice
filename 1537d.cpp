/**
 *    author:  vishnus
 *    created: 2022-07-24
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: start by thinking about odd numbers since they only have odd divisors. 
// Odd number - odd divisor = even number that is not a power of two, since that
// even number will contain the odd divisor too. Given an even number with an 
// odd divisor, the optimal idea is to subtract an odd divisor to give the other
// player an odd number. Eventually, the odd number will become prime. If the 
// number is a power of two, it is not optimal to make the number not a power 
// of two since that means you lose. So, just keep dividing by two.

int main() {
  #ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n & 1) {
      cout << "Bob" << '\n';
    } else if (n & (n - 1)) {
      cout << "Alice" << '\n';
    } else {
      cout << ((int) log2(n) & 1 ? "Bob" : "Alice") << '\n';
    }
  }
}
