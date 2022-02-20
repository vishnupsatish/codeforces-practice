#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long


void solve() {
    int n, k;

    cin >> n >> k;
    
    k++;

    vector<int> a(n + 2);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = pow(10, a[i]);
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        if (k <= 0) break;
        int to_mul;
        if (i != n) {
            to_mul = a[i + 1] / a[i] - 1;
            ans += a[i] * min(to_mul, k);
            k -= to_mul;
        } else {
            ans += a[i] * k;
            k = 0;
        }
    }

    cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}
