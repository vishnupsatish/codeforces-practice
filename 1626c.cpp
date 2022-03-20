#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: be greedy; continue a sequence only when absolutely
// required. Otherwise, start a new sequence. (Iterate backwards).


void solve() {
    int n;
    cin >> n;

    vector<ll> k(n + 2), h(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    vector<ll> seq;

    ll cur = h[n];
    ll lst = n;

    for (int i = n - 1; i >= 1; i--) {
        cur -= k[i + 1] - k[i];
        if (cur <= 0) { // Add to sequence
            seq.emplace_back((k[lst] - k[i]) + cur); // We want to start the next sequence at lst + (-cur)
            cur = h[i];
            lst = i;
        } else {
            if (cur < h[i]) {
                cur = h[i];
            }
        }
    }

    seq.emplace_back((k[lst] - k[1]) + cur);

    ll ans = 0;

    for (auto e : seq) {
        ans += e * (e + 1) / 2;
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
