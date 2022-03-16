#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Solve for probablities that are not indepedent (p1 + p2) - (p1 * p2) for all r 
// values such that r >= s where s is the point at which the suffic becomes unsorted


void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // First element in the suffix that is not sorted
    int suf = 0;
    for (int i = n; i >= 1; i--) {
        if (i != a[i]) {
            suf = i;
            break;
        }
    }

    double prob = 0;

    for (int i = 1; i <= m; i++) {
        int r; double p;
        cin >> r >> p;
        if (r >= suf) {
            if (prob == 0) {
                prob = p;
            } else {
                prob = (p + prob) - (p * prob);
            }
        }
    }

    if (suf == 0) {
        cout << 1 << '\n';
    } else {
        cout << fixed << setprecision(7) << prob << '\n';
    }
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
