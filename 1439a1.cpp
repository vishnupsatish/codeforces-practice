    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define ll long long
     
     
    void solve() {
        int n, m;
        cin >> n >> m;
     
        vector<vector<int>> a(n + 2, vector<int>(m + 2));
     
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char ca;
                cin >> ca;
                a[i][j] = (ca == '1');
            }
        }
     
        vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>>> ops;
     
        for (int i = 1; i < n; i += 2) {
            for (int j = 1; j < m; j += 2) {
                int r1 = i, r2 = i + 1, c1 = j, c2 = j + 1;
     
                vector<vector<pair<int, int>>> zo(2);
     
                zo[a[r1][c1]].emplace_back(r1, c1);
                zo[a[r2][c2]].emplace_back(r2, c2);
                zo[a[r1][c2]].emplace_back(r1, c2);
                zo[a[r2][c1]].emplace_back(r2, c1);
     
                if (zo[0].size() == 4) {
                    continue;
                }
     
                if (zo[0].size() == 1) {
                    ops.emplace_back(zo[1][0], zo[1][1], zo[1][2]);
                } else if (zo[0].size() == 2) {
                    ops.emplace_back(zo[1][0], zo[0][0], zo[0][1]);
                    ops.emplace_back(zo[1][1], zo[0][0], zo[0][1]);
                } else if (zo[0].size() == 3) {
                    ops.emplace_back(zo[0][0], zo[0][1], zo[1][0]);
                    ops.emplace_back(zo[0][0], zo[0][2], zo[1][0]);
                    ops.emplace_back(zo[0][1], zo[0][2], zo[1][0]);
                } else if (zo[0].size() == 0) {
                    ops.emplace_back(zo[1][0], zo[1][1], zo[1][2]);
                    ops.emplace_back(zo[1][0], zo[1][1], zo[1][3]);
                    ops.emplace_back(zo[1][0], zo[1][2], zo[1][3]);
                    ops.emplace_back(zo[1][1], zo[1][2], zo[1][3]);
                }
     
                a[r1][c1] = 0;
                a[r1][c2] = 0;
                a[r2][c1] = 0;
                a[r2][c2] = 0;
            }
        }
     
        if (n & 1) {
            for (int i = 1; i < m; i += 2) {
                int r1 = n - 1, r2 = n, c1 = i, c2 = i + 1;
     
                vector<vector<pair<int, int>>> zo(2);
     
                zo[a[r1][c1]].emplace_back(r1, c1);
                zo[a[r2][c2]].emplace_back(r2, c2);
                zo[a[r1][c2]].emplace_back(r1, c2);
                zo[a[r2][c1]].emplace_back(r2, c1);
     
                if (zo[0].size() == 4) {
                    continue;
                }
     
                if (zo[0].size() == 1) {
                    ops.emplace_back(zo[1][0], zo[1][1], zo[1][2]);
                } else if (zo[0].size() == 2) {
                    ops.emplace_back(zo[1][0], zo[0][0], zo[0][1]);
                    ops.emplace_back(zo[1][1], zo[0][0], zo[0][1]);
                } else if (zo[0].size() == 3) {
                    ops.emplace_back(zo[0][0], zo[0][1], zo[1][0]);
                    ops.emplace_back(zo[0][0], zo[0][2], zo[1][0]);
                    ops.emplace_back(zo[0][1], zo[0][2], zo[1][0]);
                } else if (zo[0].size() == 0) {
                    ops.emplace_back(zo[1][0], zo[1][1], zo[1][2]);
                    ops.emplace_back(zo[1][0], zo[1][1], zo[1][3]);
                    ops.emplace_back(zo[1][0], zo[1][2], zo[1][3]);
                    ops.emplace_back(zo[1][1], zo[1][2], zo[1][3]);
                }
     
                a[r1][c1] = 0;
                a[r1][c2] = 0;
                a[r2][c1] = 0;
                a[r2][c2] = 0;
            }
        }
     
        if (m & 1) {
            for (int i = 1; i < n; i += 2) {
                int r1 = i, r2 = i + 1, c1 = m, c2 = m - 1;
     
                vector<vector<pair<int, int>>> zo(2);
     
                zo[a[r1][c1]].emplace_back(r1, c1);
                zo[a[r2][c2]].emplace_back(r2, c2);
                zo[a[r1][c2]].emplace_back(r1, c2);
                zo[a[r2][c1]].emplace_back(r2, c1);
     
                if (zo[0].size() == 4) {
                    continue;
                }
     
                if (zo[0].size() == 1) {
                    ops.emplace_back(zo[1][0], zo[1][1], zo[1][2]);
                } else if (zo[0].size() == 2) {
                    ops.emplace_back(zo[1][0], zo[0][0], zo[0][1]);
                    ops.emplace_back(zo[1][1], zo[0][0], zo[0][1]);
                } else if (zo[0].size() == 3) {
                    ops.emplace_back(zo[0][0], zo[0][1], zo[1][0]);
                    ops.emplace_back(zo[0][0], zo[0][2], zo[1][0]);
                    ops.emplace_back(zo[0][1], zo[0][2], zo[1][0]);
                } else if (zo[0].size() == 0) {
                    ops.emplace_back(zo[1][0], zo[1][1], zo[1][2]);
                    ops.emplace_back(zo[1][0], zo[1][1], zo[1][3]);
                    ops.emplace_back(zo[1][0], zo[1][2], zo[1][3]);
                    ops.emplace_back(zo[1][1], zo[1][2], zo[1][3]);
                }
     
                a[r1][c1] = 0;
                a[r1][c2] = 0;
                a[r2][c1] = 0;
                a[r2][c2] = 0;
            }
        }
     
        if ((n & 1) && (m & 1)) {
            int r1 = n, r2 = n - 1, c1 = m, c2 = m - 1;
     
            vector<vector<pair<int, int>>> zo(2);
     
            zo[a[r1][c1]].emplace_back(r1, c1);
            zo[a[r2][c2]].emplace_back(r2, c2);
            zo[a[r1][c2]].emplace_back(r1, c2);
            zo[a[r2][c1]].emplace_back(r2, c1);
     
            if (zo[0].size() == 1) {
                ops.emplace_back(zo[1][0], zo[1][1], zo[1][2]);
            } else if (zo[0].size() == 2) {
                ops.emplace_back(zo[1][0], zo[0][0], zo[0][1]);
                ops.emplace_back(zo[1][1], zo[0][0], zo[0][1]);
            } else if (zo[0].size() == 3) {
                ops.emplace_back(zo[0][0], zo[0][1], zo[1][0]);
                ops.emplace_back(zo[0][0], zo[0][2], zo[1][0]);
                ops.emplace_back(zo[0][1], zo[0][2], zo[1][0]);
            } else if (zo[0].size() == 0) {
                ops.emplace_back(zo[1][0], zo[1][1], zo[1][2]);
                ops.emplace_back(zo[1][0], zo[1][1], zo[1][3]);
                ops.emplace_back(zo[1][0], zo[1][2], zo[1][3]);
                ops.emplace_back(zo[1][1], zo[1][2], zo[1][3]);
            }
     
            a[r1][c1] = 0;
            a[r1][c2] = 0;
            a[r2][c1] = 0;
            a[r2][c2] = 0;
        }
     
        assert(ops.size() <= 3 * n * m);
        
        cout << ops.size() << '\n';
     
        for (auto [p1, p2, p3] : ops) {
            cout << p1.first << ' ' << p1.second << ' ' << p2.first << ' ' << p2.second << ' ' << p3.first << ' ' << p3.second << '\n';
        }
    }
     
     
    signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
     
        int t = 1;
        cin >> t;
     
        while (t--) {
            solve();
        }
    }
