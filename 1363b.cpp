#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    string tmp;
    cin >> tmp;

    int n = tmp.size();

    vector<int> a(n + 2), psa(n + 2); // psa and ssa are for ones

    for (int i = 1; i <= n; i++) {
        a[i] = tmp[i - 1] - '0';
        psa[i] = psa[i - 1] + a[i];
    }

    int ans = 1e9;

    // Make everything after i 0, before and incl. i 1, then after i 1, before and incl. i 0
    for (int i = 1; i < n; i++) {
        ans = min(ans, psa[i] + (n - i) - (psa[n] - psa[i]));
        ans = min(ans, (i - psa[i]) + (psa[n] - psa[i]));
    }

    ans = min(ans, psa[n]);
    ans = min(ans, n - psa[n]);

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
