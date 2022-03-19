#include <bits/stdc++.h>

using namespace std;

#define int long long

// Idea: simulate a binary search algorithm and which indices it goes
// to as well as which indices must be greater than and less than the
// value that we are looking for. Use combinatorics to find the number
// of ways those 'less than' and 'greater than' places can be filled.

const int MOD = 1e9 + 7;

int fact[1003];


int pow_mod(int x, int p) {
    if (p == 0) return 1;
    int c = pow_mod(x, p / 2) % MOD;
    if (p & 1) return (((c * c) % MOD) * x) % MOD;
    return (c * c) % MOD;
}


int permutate(int n_, int r) {
    int numerator = fact[n_] % MOD;
    int denominator = (fact[n_ - r]) % MOD;
    return (numerator * pow_mod(denominator, MOD - 2)) % MOD;
}


void solve() {
    int n, x, pos;
    cin >> n >> x >> pos;

    fact[0] = fact[1] = 1;

    for (int i = 1; i <= 1001; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }

    int gr = 0, ls = 0;

    auto bs = [&] () {
        int l = 0, r = n;

        while (l < r) {
            int mid = (l + r) / 2;

            if (mid == pos) {
                l = mid + 1;
            } else if (mid <= pos) {
                l = mid + 1;
                ls++;
            } else {
                r = mid;
                gr++;
            }
        }
    };

    bs();

    int ans = ((permutate(n - x, gr) * permutate(x - 1, ls)) % MOD * (fact[n - ls - gr - 1] % MOD)) % MOD;

    cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--) {
        solve();
    }
}
