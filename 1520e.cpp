#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n;
    cin >> n;

    vector<int> a;

    ll rs = 0;

    for (int i = 1; i <= n; i++) {
        char b; cin >> b;
        if (b == '*') {
            a.emplace_back(i);
            rs += i;
        }
    }

    ll ans = 1e15;

    ll cntl = 0;
    ll cntr = a.size();

    ll ls = 0;

    for (auto e : a) {
        rs -= e;
        cntr--;

        ll lv = cntl * e - ls - (cntl * (cntl + 1) / 2);
        ll lr = abs(abs(cntr * e - rs) - (cntr * (cntr + 1) / 2));

        ls += e;
        cntl++;
        ans = min(ans, lv + lr);
    }

    cout << (ans == 1e15 ? 0 : ans) << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}
