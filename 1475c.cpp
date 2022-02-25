#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int ac, bc, k;
    cin >> ac >> bc >> k;

    vector<int> a(k + 2), b(k + 2);
    unordered_map<int, vector<int>> acnt;
    unordered_map<int, vector<int>> bcnt;

    multiset<int> allb;

    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        allb.emplace(a[i]);
    }

    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= k; i++) {
        acnt[a[i]].emplace_back(b[i]);
        bcnt[b[i]].emplace_back(a[i]);
    }

    ll ans = 0;

    for (auto [kv, ele] : acnt) {
        for (auto p : ele) {
            ans += max(0ll, (ll) (k - (bcnt[p].size() - 1) - ele.size()));
        }
    }

    cout << ans / 2 << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) solve();
}
