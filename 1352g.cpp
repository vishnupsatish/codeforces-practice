/**
 *    author:  vishnus
 *    created: 2022-05-05
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: easy construction

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n <= 3) {
      cout << -1 << '\n';
      continue;
    }
    int idx = 0;
    vector<int> a(n);
    for (int i = n - (n & 1); i >= 6; i -= 2) {
      a[idx++] = i;
    }
    a[idx++] = 2;
    a[idx++] = 4;
    for (int i = 1; i <= n; i += 2) {
      a[idx++] = i;
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
}
