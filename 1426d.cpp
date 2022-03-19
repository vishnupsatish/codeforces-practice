#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: subarray sum from l to r will be 0 if psa[r] == psa[l - 1]. Once we
// "fix" a smaller range, any bigger range outside it will also be fixed.
// Iterate, and hold all prefix sums up to that value. If such a prefix sum
// exists, remove all prefix sums since we have fixed all subarrays up to there.


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2);
    vector<ll> psa(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = psa[i - 1] + a[i];
    }

    unordered_set<ll> p; // Holds PSA value
    p.emplace(0);

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (p.contains(psa[i])) {
            ans++;
            p.clear();
        }

        p.emplace(psa[i - 1]);
    }

    cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--) {
        solve();
    }
}
