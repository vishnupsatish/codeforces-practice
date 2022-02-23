#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n;
    cin >> n;

    vector<int> u(n + 2);
    vector<vector<ll>> s(n + 2);
    vector<ll> ans(n + 2);

    for (int i = 1; i <= n; i++) cin >> u[i];

    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        s[u[i]].emplace_back(c);
    }

    for (int i = 1; i <= n; i++) sort(s[i].begin(), s[i].end(), greater<>());

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < s[i].size(); j++) s[i][j] += s[i][j - 1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s[i].size(); j++) {
            ans[j] += s[i][s[i].size() / j * j - 1];
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}


signed main() {
    int t; cin >> t;

    while (t--) solve();
}
