#include <bits/stdc++.h>

using namespace std;

// Idea: more tricky implementation than anything. First check if there are three or more shaded
// cells in a row (invalid case). Then, create all "L"s by finding their middle element. Then
// check that all shaded cells are part of an "L". Then check for all shaded cells, there
// are no corner-adjacent shaded cells that are part of a different "L".

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        a[i][j] = (c == '*' ? 1 : 0);
      }
    }
    auto CheckInvalid = [&](int i, int j) {
      if (i != 0 && a[i - 1][j] && i != n - 1 && a[i + 1][j]) {
        return true;
      }
      if (j != 0 && a[i][j - 1] && j != m - 1 && a[i][j + 1]) {
        return true;
      }
      return false;
    };
    bool invalid = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j]) {
          invalid = CheckInvalid(i, j);
        }
        if (invalid) {
          break;
        }
      }
      if (invalid) {
        break;
      }
    }
    if (invalid) {
      cout << "NO" << '\n';
      continue;
    }
    int cnt = 1;
    vector<vector<int>> val(n, vector<int>(m, -1)); // If a shaded cell has already been used as part of "L"
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!a[i][j]) {
          continue;
        }
        vector<pair<int, int>> adj;
        if (i != 0 && a[i - 1][j]) {
          adj.push_back({i - 1, j});
        }
        if (i != n - 1 && a[i + 1][j]) {
          adj.push_back({i + 1, j});
        }
        if (j != 0 && a[i][j - 1]) {
          adj.push_back({i, j - 1});
        }
        if (j != m - 1 && a[i][j + 1]) {
          adj.push_back({i, j + 1});
        }
        if ((int) adj.size() == 2) {
          val[i][j] = cnt;
          for (auto [k, l] : adj) {
            val[k][l] = cnt;
          }
          cnt++;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j]) {
          if (val[i][j] == -1) {
            invalid = true;
          }
          if (i != 0 && j != 0 && a[i - 1][j - 1] && val[i - 1][j - 1] != val[i][j]) {
            invalid = true;
          }
          if (i != 0 && j != m - 1 && a[i - 1][j + 1] && val[i - 1][j + 1] != val[i][j]) {
            invalid = true;
          }
          if (i != n - 1 && j != 0 && a[i + 1][j - 1] && val[i + 1][j - 1] != val[i][j]) {
            invalid = true;
          }
          if (i != n - 1 && j != m - 1 && a[i + 1][j + 1] && val[i + 1][j + 1] != val[i][j]) {
            invalid = true;
          }
        }
      }
    }
    if (invalid) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
  }
}
