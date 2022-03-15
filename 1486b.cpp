#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Key is median. All points between two medians work. Multiply to find all possibilities.


void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    if (n & 1) {
        cout << 1 << '\n';
    } else {
        cout << (ll) (x[n / 2] - x[n / 2 - 1] + 1) * (ll) (y[n / 2] - y[n / 2 - 1] + 1) << '\n';
    }
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
