#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: Use DP to find which ones to remove. Greedy does not work here. dp[i][j] is the
// largest amount you can remove from speed limits 1 -> n if removing <= j elements.
// pc[i][j] stores how much we benefit if we remove the previous j elements starting
// from and including item i. For dp[i][j], once we remove the previous m (m | m <= j)
// elements, we must take the value of dp[i - m - 1][j - m]. Try all values of m.


void solve() {
    int n, l, k;
    cin >> n >> l >> k;

    vector<int> d(n + 2), a(n + 2);
    vector<vector<int>> dp(n + 2, vector<int>(k + 2));
    vector<vector<int>> pc(n + 2, vector<int>(n + 2)); // How much do we benefit if we remove the previous j elements (including the current one)?
    vector<int> ans(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    d[n + 1] = l;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1] + a[i] * (d[i + 1] - d[i]);
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            pc[i][j] = (ans[i] - (ans[i - j - 1] + a[i - j] * (d[i + 1] - d[i - j])));
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= min(k, i - 1); j++) {
            for (int m = 1; m <= j; m++) {
                dp[i][j] = max(dp[i][j], dp[i - m - 1][j - m] + pc[i][m]);
            }

            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], 0);
        }
    }

    cout << ans[n] - dp[n][k] << '\n';
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--) {
        solve();
    }
}
