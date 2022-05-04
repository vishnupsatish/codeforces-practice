/**
 *    author:  vishnus
 *    created: 2022-05-04
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/a/GJSlmpm

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    --x;
    if (n == 1) {
      cout << "Ayush" << '\n';
      continue;
    }
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      deg[u]++;
      deg[v]++;
    }
    if (deg[x] == 1) {
      cout << "Ayush" << '\n';
      continue;
    }
    cout << ((n & 1) ? "Ashish" : "Ayush") << '\n';
  }
}
