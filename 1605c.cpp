#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n; string s;

    cin >> n >> s;

    for (int len = 1; len <= 6; len++) {
        for (int i = 0; i + len < n; i++) {
            int j = i + len;
            int a = 0, b = 0, c = 0;

            for (int k = i; k <= j; k++) {
                a += (s[k] == 'a');
                b += (s[k] == 'b');
                c += (s[k] == 'c');
            }

            if (a > b && a > c) {
                cout << len + 1 << '\n';
                return;
            }
        }
    }

    cout << -1 << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}
