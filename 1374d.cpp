#include <bits/stdc++.h>

using namespace std;

// The optimal strategy is to go cyclic. Start at mod k = k - 1, 
// go to mod k = k - 2, and so on, since we will be incrementing 
// x in the minimal possible way. When you do so, for example, 
// for mod k = 1 (when k = 3), we will be getting 3, 6, 9, 12, ..., 
// and calculate the largest difference (12-1) + 1 which is the answer.  
// Once we go cyclic starting at the greatest mod value, we will be
// Able to go all the way to mod k = 1 without incrementing by k overall

#define ll long long


void solve() {
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> md;

    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        if (b % k != 0) {
            md[b % k]++;
        }
    }

    ll ans = 0;

    for (auto [mod, v] : md) {
        ans = max(ans, (ll) v * (ll) k - ((ll) mod) + 1);
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
