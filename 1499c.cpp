#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n;
    cin >> n;

    vector<ll> c(n + 2), l(n + 2), r(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    ll s = 0;
    ll mi = 1e9;
    int cnt = 0;
    for (int i = 1; i <= n; i += 2) {
        s += c[i];
        mi = min(c[i], mi);
        l[i] = mi * (n - cnt) + (s - mi);
        cnt++;
    }

    s = 0;
    mi = 1e9;
    cnt = 0;
    for (int i = 2; i <= n; i += 2) {
        s += c[i];
        mi = min(c[i], mi);
        r[i] = mi * (n - cnt) + (s - mi);
        cnt++;
    }

    ll ans = l[1] + r[2];

    if (n & 1) {
        ans = min(ans, l[n] + r[n - 1]);
    } else {
        ans = min(ans, l[n - 1] + r[n]);
    }

    for (int i = 2; i < n; i++) {
        if (i & 1) {
            ans = min(ans, l[i] + r[i + 1]);
            ans = min(ans, l[i] + r[i - 1]);
        } else {
            ans = min(ans, r[i] + l[i + 1]);
            ans = min(ans, r[i] + l[i - 1]);
        }
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
