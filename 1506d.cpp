#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2);
    unordered_map<int, int> allcnt;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        allcnt[a[i]]++;
    }

    int cnt = 0;

    for (auto [k, v] : allcnt) {
        cnt = max(cnt, v);
    }

    if (cnt >= (n - cnt)) {
        cout << cnt - (n - cnt) << '\n';
    } else {
        cout << (n & 1) << '\n';
    }
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}
