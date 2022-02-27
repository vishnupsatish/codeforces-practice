#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 2), ans(n + 2);

    ll s = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }

    ans[1] = a[1];

    for (int i = 2; i <= n; i++) {
        ll cur = a[i] / ans[i - 1];
        ans[i] = max(1ll, ans[i - 1] * cur);
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) solve();
}
