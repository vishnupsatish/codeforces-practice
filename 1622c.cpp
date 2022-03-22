#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: Optimal strategy is to take the min element, subtract some amount of times, 
// then set x of the greatest elements to the subtracted min element. Loop the suffix
// of which we should set the min element to and binary search to find what we should
// subtract the least element by.


void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n + 2), psa(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.begin() + n + 1);

    for (int i = 1; i <= n; i++) {
        psa[i] = psa[i - 1] + a[i];
    }

    if (psa[n] <= k) {
        cout << 0 << '\n';
        return;
    }

    ll ans = psa[n] - k;

    for (ll i = n; i >= 2; i--) { // Set all elements from i -> n to a[1] minus some number (binary search to find that number)
        ll l = 0, r = 2e9;
        while (l < r) {
            ll mid = (l + r) / 2;

            ll val = psa[n] - a[1] + (a[1] - mid) - (psa[n] - psa[i - 1]) + (a[1] - mid) * (n - i + 1);

            if (val <= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans = min(ans, l + (n - i + 1));
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
