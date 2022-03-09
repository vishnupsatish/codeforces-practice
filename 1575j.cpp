#include <bits/stdc++.h>

using namespace std;

// Idea: calculate which positions take us straight down, aside from that do simulation.


void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n + 2, vector<int> (m + 2)), dn(n + 2, vector<int> (m + 2));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = n; i >= 1; i--) {
            if (a[i][j] != 2) {
                break;
            }
            dn[i][j] = 1;
        }
    }

    auto down = [&] (int c) {
        int r = 1;

        if (dn[r][c]) {
            return c;
        }

        int curr = c;
        bool cset = false;

        while (r != n + 1) {
            if (a[r][c] == 1) {
                if (dn[r + 1][c]) {
                    dn[r][c] = 1;
                }
                a[r][c] = 2;
                c++;
                cset = false;
                curr = r;
            } else if (a[r][c] == 3) {
                if (dn[r + 1][c]) {
                    dn[r][c] = 1;
                }
                a[r][c] = 2;
                c--;
                cset = false;
                curr = r;
            } else {
                if (dn[r][c]) {
                    for (int i = curr; i <= n; i++) {
                        dn[i][c] = 1;
                    }

                    return c;
                }

                if (!cset) {
                    curr = r;
                    cset = true;
                }
                r++;
            }
        }

        return c;
    };

    for (int i = 1; i <= k; i++) {
        int c;
        cin >> c;

        cout << down(c) << ' ';
    }
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--) {
        solve();
    }
}

