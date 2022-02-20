#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXAI = 1e6;

int sieve[MAXAI + 3];


void solve() {
    int n, e;

    cin >> n >> e;

    vector<int> a(n + 3);

    for (int i = 1; i <= n; i++) cin >> a[i];

    ll ans = 0;

    for (int i = 1; i <= e; i++) {
        int cpr = 0;
        unordered_map<int, int> os;

        for (int j = i; j <= n; j += e) {
            if (a[j] != 1 && !sieve[a[j]]) {
                if (cpr >= 1) {
                    for (int l = 0; l < cpr; l++) {
                        ans += (ll)os[l] * (ll)os[l + 1] + (ll)os[l] + (ll)os[l + 1];
                    }
                }
                cpr = 0;
                os.clear();
                continue;
            }

            if (sieve[a[j]]) {
                cpr++;
            } else if (a[j] == 1) {
                os[cpr]++;
            }
        }

        if (cpr >= 1) {
            for (int j = 0; j < cpr; j++) {
                ans += (ll)os[j] * (ll)os[j + 1] + (ll)os[j] + (ll)os[j + 1];
            }
        }
    }

    cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    fill(begin(sieve), end(sieve), 1);

    sieve[0] = sieve[1] = 0;

    for (int i = 2; i * i <= MAXAI; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= MAXAI; j += i) sieve[j] = 0;
        }
    }

    int t; cin >> t;

    while (t--) solve();
}
