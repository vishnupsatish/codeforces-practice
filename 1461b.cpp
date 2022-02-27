#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n + 2, vector<char> (m + 2));
    vector<vector<int>> dp(n + 2, vector<int> (m + 2));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    ll ans = 0;

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '*') {
                dp[i][j] = 1 + min(dp[i + 1][j - 1], min(dp[i + 1][j + 1], dp[i + 1][j]));
                ans += dp[i][j];
            }
        }
    }

    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) solve();
}
