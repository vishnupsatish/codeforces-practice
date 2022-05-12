/**
 *    author:  vishnus
 *    created: 2022-05-11
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: first make all chips move to (1, 1). Then, go through each and every
// cell in a zig-zag pattern. Total number of moves: (n - 1) + (m - 1) + (nm - 1)
// = nm + n + m - 3 which fits the constraints.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  cout << n + m + n * m - 3 << '\n';
  for (int i = 0; i < n - 1; i++) {
    cout << 'U';
  }
  for (int i = 0; i < m - 1; i++) {
    cout << 'L';
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << 'D';
    }
    char dir = (i & 1) ? 'L' : 'R';
    for (int j = 0; j < m - 1; j++) {
      cout << dir;
    }
  }
  cout << '\n';
}
