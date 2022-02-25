#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<pair<ll, int>> a(n + 2);
    vector<ll> psa(n + 2);

    for (int i = 1; i <= n; i++) {
        ll c; cin >> c;
        a[i] = {c, i};
    }

    sort(a.begin() + 1, a.begin() + n + 1);

    for (int i = 1; i <= n; i++) {
        psa[i] = psa[i - 1] + a[i].first;
    }

    set<int> ans;

    for (int i = n - 1; i >= 1; i--) {
        if (psa[i] < a[i + 1].first) {
            break;
        } else {
            ans.emplace(a[i].second);
        }
    }

    ans.emplace(a[n].second);

    cout << ans.size() << '\n';

    for (auto e : ans) cout << e << ' ';
    cout << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) solve();
}
