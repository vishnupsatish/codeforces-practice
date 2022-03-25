/**
 *    author:  vishnus
 *    created: 2022-03-24
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if n is even, just set pairs of numbers to sum to zero. If n is odd, 
// for the last three numbers use the idea of the distributive property.

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &e : a) {
      cin >> e;
    }
    if (n & 1) {
      for (int i = 0; i < n - 3; i += 2) {
        cout << -a[i + 1] << ' ' << a[i] << ' ';
      }
      if (a[n - 2] + a[n - 3] != 0) {
        cout << -a[n - 1] << ' ' << -a[n - 1] << ' ' << a[n - 2] + a[n - 3] << '\n';
      } else if (a[n - 1] + a[n - 2] != 0) {
        cout << a[n - 1] + a[n - 2] << ' ' << -a[n - 3] << ' ' << -a[n - 3] << '\n';
      } else if (a[n - 1] + a[n - 3] != 0) {
        cout << -a[n - 2] << ' ' << a[n - 1] + a[n - 3] << ' ' << -a[n - 2] << '\n';
      }
    } else {
      for (int i = 0; i < n; i += 2) {
        cout << -a[i + 1] << ' ' << a[i] << ' ';
      }
      cout << '\n';
    }
  }
}
