#include <bits/stdc++.h>

using namespace std;

// Idea: let k = max(ceil(sum / (n - 1)), max element of the array). k is how much we want
// each of the n - 1 blocks to be. (min value that each of them can be). It must be max,
// but if the ceiling of sum / (n - 1) is greater, then once making the max, there will
// be more than the max remaining, so make that. For the nephew to be happy, the sum of a
// should be divisible by n - 1. We therefore want the array to have a sum of (n - 1) * k.

#define ll long long


void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 2);

    ll s = 0, ma = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
        ma = max(ma, a[i]);
    }

    cout << (ll) ((n - 1) * max(ceil((double) s / (double )(n - 1)), (double) ma) - s) << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) solve();
}
