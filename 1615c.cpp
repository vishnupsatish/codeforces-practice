#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: define how to get rid of a rogue one and zero. Or if the answer is
// an odd number of operations, how to get rid of a rogue one or zero. (minus
// one since we start by getting rid of a one)


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2), b(n + 2);

    string at, bt;
    cin >> at >> bt;

    if (at == bt) {
        cout << 0 << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        a[i + 1] = at[i] - '0';
    }

    for (int i = 0; i < n; i++) {
        b[i + 1] = bt[i] - '0';
    }

    int zz, zo, oz, oo;
    zz = zo = oz = oo = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] && b[i]) {
            oo++;
        } else if (a[i]) {
            oz++;
        } else if (b[i]) {
            zo++;
        } else {
            zz++;
        }
    }

    int ans = 1e9;

    if (oo - 1 == zz) {
        ans = oo * 2 - 1;
    }

    if (oz == zo) {
        ans = min(ans, oz * 2);
    }

    if (ans == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
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
