#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n, x;
    cin >> n >> x;

    vector<ll> a(n + 2);
    vector<int> dp(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.begin() + n + 1, greater<>());

    dp[1] = a[1] >= x ? 1 : 0;

    int ans = dp[1];

    for (int i = 2; i <= n; i++) {
        if (a[i] * i < x) {
            dp[i] = 0;
        } else {
            dp[i] = dp[i - ((x / a[i]) + (x % a[i] != 0))] + 1;
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
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
