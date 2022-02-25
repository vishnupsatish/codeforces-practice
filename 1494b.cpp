#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;

    // lcnt is how much l should have at least. oolr is how much combined l and r should have.
    int lcnt = 0, rcnt = 0, ucnt = 0, dcnt = 0, oolr = 0, ooud = 0;

    if (d == n) {
        lcnt++;
        rcnt++;
        oolr += 2;
    }

    if (u == n) {
        lcnt++;
        rcnt++;
        oolr += 2;
    }

    if (r == n) {
        ucnt++;
        dcnt++;
        ooud += 2;
    }

    if (l == n) {
        ucnt++;
        dcnt++;
        ooud += 2;
    }

    if (d == n - 1) {
        oolr++;
    }

    if (u == n - 1) {
        oolr++;
    }

    if (l == n - 1) {
        ooud++;
    }

    if (r == n - 1) {
        ooud++;
    }

    if (ooud <= u + d && oolr <= l + r && lcnt <= l && rcnt <= r && ucnt <= u && dcnt <= d) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) solve();
}
