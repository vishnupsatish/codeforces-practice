#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: since c < m, we know that all positive differences and negative differences 
// must be the same. If it is an arithmetic sequence, answer is 0. If any there is more 
// than one positive or negative difference, answer is -1. Otherwise, we know that 
// (x+c) % m = x + c or x + c - m, so find m and c based on the positive and negative difference.


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2);

    bool ok = false;
    int fst;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        if (i == 1) {
            fst = a[i];
        } else {
            if (fst != a[i]) {
                ok = true;
            }
        }
    }

    if (!ok) {
        cout << 0 << '\n';
        return;
    }

    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            cout << -1 << '\n';
            return;
        }
    }

    unordered_set<int> pos;
    unordered_set<int> neg;

    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i - 1]) {
            pos.emplace(a[i] - a[i - 1]);
        } else {
            neg.emplace(a[i - 1] - a[i]);
        }
    }

    if (pos.size() > 1 || neg.size() > 1) {
        cout << -1 << '\n';
        return;
    }

    if (pos.empty() || neg.empty()) {
        cout << 0 << '\n';
        return;
    }

    int c = *pos.begin();

    int md = *neg.begin() + c;

    for (int i = 1; i <= n; i++) {
        if (a[i] >= md) {
            cout << -1 << '\n';
            return;
        }

        if (i == 1) {
            fst = a[i];
        } else {
            fst += c;
            if (fst > a[i]) {
                fst %= md;
                if (fst != a[i]) {
                    cout << -1 << '\n';
                    return;
                }
            } else if (fst != a[i]) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    cout << md << ' ' << c << '\n';
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
