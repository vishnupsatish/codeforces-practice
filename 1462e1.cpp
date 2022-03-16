#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Counting problem.


void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 2), cnt(n + 3);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        // Try making i min and i + 1 max
        if (cnt[i] && cnt[i + 1]) {
            ans += max(0ll, (cnt[i + 1]) * ((cnt[i]) * (cnt[i] - 1) / 2));
            ans += max(0ll, (cnt[i]) * (cnt[i + 1] * (cnt[i + 1] - 1) / 2));
        }
        // Try making i min and i + 2 max
        if (cnt[i] && cnt[i + 2]) {
            ans += max(0ll, (cnt[i + 2]) * (cnt[i]) * (cnt[i + 1]));
            ans += max(0ll, (cnt[i + 2]) * ((cnt[i]) * (cnt[i] - 1) / 2));
            ans += max(0ll, (cnt[i]) * ((cnt[i + 2]) * (cnt[i + 2] - 1) / 2));
        }
        // Try making i min and i max
        if (cnt[i] >= 3) {
            ans += max(0ll, cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6);
        }
    }

    cout << ans << '\n';
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
