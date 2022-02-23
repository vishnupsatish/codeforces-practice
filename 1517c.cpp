#include <bits/stdc++.h>

using namespace std;


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> a(n + 2);
    vector<vector<int>> ans(n + 2, vector<int>(n + 2));

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        int r = i, c = i;

        ans[r][c] = a[i];

        for (int j = 1; j < a[i]; j++) {
            if (ans[r][c - 1] == 0 && c - 1 >= 1) {
                ans[r][c - 1] = a[i];
                c--;
            }
            else if (ans[r + 1][c] == 0 && r + 1 <= n) {
                ans[r + 1][c] = a[i];
                r++;
            }
            else {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}
