#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n + 2), psa(n + 2), ms(n + 2, -1e9);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = psa[i - 1] + a[i];
    }

    for (int len = 1; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if (ms[len] == -1e9) {
                ms[len] = psa[j] - psa[i - 1];
            } else {
                ms[len] = max(ms[len], psa[j] - psa[i - 1]);
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            ans = max(ans, ms[j] + x * min(j, i));
        }
        cout << ans << ' ';
    }
    cout << '\n';
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
