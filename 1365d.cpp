/**
*  author:  vishnus
*  created: 2022-08-27
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: make neighbouring cells of 'B' walls and flood fill. so easy.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    int gcnt = 0, bcnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        gcnt += a[i][j] == 'G';
        bcnt += a[i][j] == 'B';
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'B') {
          for (auto [dr, dc] : d) {
            int nr = dr + i;
            int nc = dc + j;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] != 'B') {
              if (a[nr][nc] == 'G') {
                ok = false;
                break;
              }
              a[nr][nc] = '#';
              if (nr == n - 1 && nc == m - 1 && gcnt >= 1) {
                ok = false;
                break;
              }
            }
          }
        }
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    vector<vector<int>> vis(n, vector<int>(m));
    queue<pair<int, int>> q;
    q.push({n - 1, m - 1});
    vis[n - 1][m - 1] = 1;
    while (!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();
      for (auto [dr, dc] : d) {
        int nr = dr + r;
        int nc = dc + c;
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && a[nr][nc] != '#') {
          q.push({nr, nc});
          vis[nr][nc] = 1;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'G' && !vis[i][j]) {
          ok = false;
          break;
        }
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
  }
}
