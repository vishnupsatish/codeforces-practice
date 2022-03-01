#include <bits/stdc++.h>

using namespace std;

// Idea: binary search for answer

#define ll long long


void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 2), b(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    auto check = [&](ll time) -> bool {
        ll su = 0;

        for (int i = 1; i <= n; i++) {
            if (a[i] > time) {
                su += b[i];
            }
        }

        return su <= time;
    };

    ll l = 0, r = 1e9;

    while (l < r) {
        ll mid = (l + r) / 2;

        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}
