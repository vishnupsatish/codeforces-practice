#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: find number of bad combinations using combinatorics.

const int MOD = 998244353;

ll fact[200003];


ll pow_mod(ll x, int p) {
    if (p == 0) return 1;
    ll c = pow_mod(x, p / 2) % MOD;
    if (p & 1) return (((c * c) % MOD) * x) % MOD;
    return (c * c) % MOD;
}


ll choose(int n_, int r) {
    ll numerator = fact[n_] % MOD;
    ll denominator = (fact[r] * fact[n_ - r]) % MOD;
    return (numerator * pow_mod(denominator, MOD - 2)) % MOD;
}


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2);
    map<int, int, greater<>> cnt;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    if ((*cnt.begin()).second >= 2) {
        cout << fact[n] << '\n';
        return;
    }

    if (cnt[(*cnt.begin()).first - 1] == 0) {
        cout << 0 << '\n';
        return;
    }

    ll ans = fact[n];
    int ss = cnt[(*cnt.begin()).first - 1]; // How many of the second-last do we have?
    int nt = n - ss - 1;

    for (int i = ss + 1; i <= n; i++) {
        ans -= ((fact[i - 1] * fact[n - i]) % MOD * choose(nt, i - ss - 1)) % MOD;
        ans += MOD;
        ans %= MOD;
    }

    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;

    for (int i = 1; i <= 2e5; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}

