#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<vector<int>> a(n + 2, vector<int>(m + 2)), vis(n + 2, vector<int>(m + 2));

    vector<tuple<int, int, int>> moves = {{1, 0, 2}, {-1, 0, 8}, {0, 1, 4}, {0, -1, 1}};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }

    multiset<int, greater<>> ans;

    auto bfs = [&] (pii src) -> void {
        queue<pii> q;
        q.emplace(src);

        int cnt = 1;

        while (!q.empty()) {
            pii u = q.front(); q.pop();
            int r = u.first, c = u.second;

            for (auto [dr, dc, shft] : moves) {
                // No wall blocking movement
                if (!(a[r][c] & shft) && !vis[r + dr][c + dc]) {
                    q.emplace(r + dr, c + dc);
                    vis[r + dr][c + dc] = 1;
                    cnt++;
                }
            }
        }

        ans.emplace(cnt - (cnt != 1));
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) bfs({i, j});
        }
    }

    for (auto e : ans) cout << e << ' ';
    cout << '\n';
}
