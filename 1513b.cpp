#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: we know that the two smallest numbers must be placed at the ends, and the bitwise
// AND of the entire sequence must be equal to the smallest element, otherwise there are no
// possibilities. Find all ways to place the two smallest elements, then find all permutations
// to place the rest of the elements. Multiply those, and you have the answer.

const int MOD = 1e9 + 7;


void solve(vector<ll> &fact) {
    int n;
    cin >> n;

    vector<int> a(n + 2);

    int m = 1e9;

    int an;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        if (i == 1) an = a[i];
        else an &= a[i];

        m = min(a[i], m);
    }

    ll cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] == m) cnt++;
    }

    if (cnt == 1 || m != an) {
        cout << 0 << '\n';
        return;
    }

    cout << ((cnt * (cnt - 1) % MOD) * fact[n - 2]) % MOD << '\n';
}


signed main() {
    vector<ll> fact(2e5 + 3);

    fact[0] = 1;

    for (ll i = 1; i <= 2e5; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve(fact);
}
