/**
 *    author:  vishnus
 *    created: 2022-04-19
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if we look the binary digits of a certain range 0 -> n, we see that at each digit, 
// the number of zeroes is either greater than or equal to the number of ones at that position.
// Common logic states that in 'a', if we were to find the number of zeroes and ones and each
// position, if, at a certain position the number of zeroes is greater, don't change that 
// and keep it a 0. Otherwise, change it. If they're equal, we can do anything. This is correct
// since an answer always exists.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;
    int n = r + 1;
    vector<bitset<18>> a(n);
    for (int i = 0; i < n; i++) {
      int ca;
      cin >> ca;
      a[i] = bitset<18>(ca);
    }
    bitset<18> ans;
    vector<vector<int>> cnt(18, vector<int>(2)); // Counts the number of 0s and 1s at the ith position
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 18; j++) {
        cnt[j][a[i][j]]++;
      }
    }
    for (int i = 0; i < 18; i++) {
      if (cnt[i][0] > cnt[i][1]) {
        ans[i] = 0;
      } else if (cnt[i][0] < cnt[i][1]) {
        ans[i] = 1;
      } else {
        ans[0] = 1;
      }
    }
    cout << ans.to_ulong() << '\n';
  }
}
