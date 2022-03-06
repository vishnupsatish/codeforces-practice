#include <bits/stdc++.h>

using namespace std;

#define ll long long

// We know how to calculate answer for all powers of 2. All set 
// bits indicate how to break the number down into powers of 2.


void solve() {
    ll n;
    cin >> n;

    ll ans = 0;

    string b = bitset<64>(n).to_string();

    for (ll i = 0; i < 64; i++) {
        if (b[i] == '1') {
            ans += (1ll << (64 - i - 1)) * 2 - 1;
        }
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
