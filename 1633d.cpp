#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: use DP to find the minimum number of operations to make a value,
// then use knapsack since we have weights (operations) and values (the
// array c) and a bound on the weight (k).


void solve() {
    int n, k;
    cin >> n >> k;

    k = min(k, 20 * n);

    vector<int> b(n + 2), c(n + 2), op(1e3 + 2, 1e9);
    vector<vector<int>> dp(n + 2, vector<int>(k + 2));

    op[1] = 0;

    for (int i = 1; i <= 1e3; i++) {
        for (int j = 1; j <= i; j++) {
            if (i + i / j <= 1000) {
                op[i + i / j] = min(op[i + i / j], op[i] + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j < op[b[i]]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - op[b[i]]] + c[i]);
            }
        }
    }

    cout << dp[n][k] << '\n';
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
