#include <bits/stdc++.h>

using namespace std;

// Idea: try to remove no cell, one cell, two cells... all the way to n.
// Then determine the answer if we removed that many cells by using an
// array which tracks how many cells have no platform from i -> n, i += k

#define ll long long


void solve() {
    int n, p, k;
    cin >> n >> p >> k;

    vector<int> a(n + 2);

    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        a[i] = c - '0';
    }

    ll x, y;
    cin >> x >> y;

    vector<int> cnt(n + 2); // Count of all cells with no platform from i -> n, i += k

    for (int i = n; i >= 1; i--) {
        if (i + k > n) {
            cnt[i] = !a[i];
        } else {
            cnt[i] = !a[i] + cnt[i + k];
        }
    }

    ll ans = 1e18;

    for (int i = p; i <= n; i++) { // Try to remove none, first, second, third, so on all the way to n, then use cnt to determine the solution for this value of i
        ans = min(ans, (i - p) * y + cnt[i] * x);
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
