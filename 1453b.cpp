#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/a/4Vv1BgS (nice problem, 10/10 would recommend)

#define ll long long


void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll og = 0;

    for (int i = 2; i <= n; i++) {
        og += abs(a[i] - a[i - 1]);
    }

    ll rm = max(abs(a[2] - a[1]), abs(a[n] - a[n - 1]));

    for (int i = 2; i < n; i++) {
        rm = max(rm, abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]) - abs(a[i - 1] - a[i + 1]));
    }

    cout << og - rm << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) solve();
}
