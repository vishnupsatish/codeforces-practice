/**
 *    author:  vishnus
 *    created: 2022-04-01
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: The total number of open brackets in both a and b must be n in total
// (and in each must be n / 2). Each 1 creates an even number of open brackets
// in a and b (either 2 or 0), and each 0 creates an odd number of open brackets
// (1), so there must be an even number of 0s. Imagine there are k 1s. Make
// k/2 1s open brackets and the other k/2 1s closing brackets. This balances
// the ones. For each 0, alternate open and closing brackets. This balances the zeroes
// and makes sure that there are no negative stack values at any point.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> s(n);
    int zcnt = 0;
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      s[i] = (int) c - '0';
      zcnt += !s[i];
    }
    int ocnt = n - zcnt;
    if (!s[0] || !s[n - 1] || (zcnt & 1)) {
      cout << "NO" << '\n';
      continue;
    }
    vector<char> a(n), b(n);
    int cocnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 1) {
        cocnt++;
        if (cocnt <= ocnt / 2) {
          a[i] = '(';
          b[i] = '(';
        } else {
          a[i] = ')';
          b[i] = ')';
        }
      }
    }
    int zcur = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 0) {
        zcur++;
        if (zcur & 1) {
          a[i] = '(';
          b[i] = ')';
        } else {
          a[i] = ')';
          b[i] = '(';
        }
      }
    }
    #ifdef LOCAL
    int stka = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '(') {
        stka++;
      } else {
        stka--;
      }
      assert(stka >= 0);
    }
    assert(stka == 0);
    int stkb = 0;
    for (int i = 0; i < n; i++) {
      if (b[i] == '(') {
        stkb++;
      } else {
        stkb--;
      }
      assert(stkb >= 0);
    }
    assert(stkb == 0);
    #endif
    cout << "YES" << '\n';
    for (auto &e : a) {
      cout << e;
    }
    cout << '\n';
    for (auto &e : b) {
      cout << e;
    }
    cout << '\n';
  }
}
