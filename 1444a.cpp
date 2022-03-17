#include <bits/stdc++.h>

using namespace std;

#define ll long long

// p must be divisible by q for the answer to not be p. The answer then must be the largest factor
// for p that is not divisible by q. What will this be? The largest number such that any one of
// its prime factor exponents is less than q's respective exponent. We can find all prime factors
// of q and divide p by powers of each prime factor to find possible values for x since we cannot
// directly prime factorize p.


void solve() {
    ll p; int q;
    cin >> p >> q;

    int oq = q;

    if (p % q != 0) {
        cout << p << '\n';
        return;
    }

    unordered_map<int, int> pr;

    while (q % 2 == 0) {
        q /= 2;
        pr[2]++;
    }

    for (int i = 3; i <= sqrt(q); i += 2) {
        while (q % i == 0) {
            q /= i;
            pr[i]++;
        }
    }

    if (q != 1) {
        pr[q]++;
    }

    ll x = 0;

    for (auto [k, v] : pr) {
        ll s = k;
        while (p % s == 0) {
            if ((p / s) % oq != 0) {
                x = max(x, p / s);
            }
            s *= k;
        }
    }

    cout << x << '\n';
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
