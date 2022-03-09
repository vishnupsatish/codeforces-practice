#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n + 2, vector<int> (m + 2)), vis(n + 2, vector<int> (m + 2));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            a[i][j] = c == '*' ? 1 : 0;
        }
    }

    auto tick = [&] (int r, int c) {
        int cnt = 0;

        for (int i = 1; i <= r - 1; i++) {
            int c1 = c - i;
            int c2 = c + i;

            if (c1 <= 0 || c2 >= m + 1) {
                break;
            }

            if (a[r - i][c1] == 0 || a[r - i][c2] == 0) {
                break;
            }

            cnt++;
        }

        if (cnt >= k) {
            vis[r][c] = 1;

            for (int i = 1; i <= cnt; i++) {
                int c1 = c - i;
                int c2 = c + i;

                vis[r - i][c2] = 1;
                vis[r - i][c1] = 1;
            }
        }

        return cnt;
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) {
                tick(i, j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && a[i][j]) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    cout << "YES" << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}

