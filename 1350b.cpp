#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2), dp(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) {
                if (a[j] < a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }

                if (a[i / j] < a[i]) {
                    dp[i] = max(dp[i], dp[i / j] + 1);
                }
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans + 1 << '\n';
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
