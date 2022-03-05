#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2), b(n + 2), inda(n + 2), ans(n + 2); // Inda: maps value to index for a

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        inda[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int ma = 0;

    for (int i = 1; i <= n; i++) {
        if (inda[b[i]] >= i) {
            ans[inda[b[i]] - i]++;
            ma = max(ma, ans[inda[b[i]] - i]);
        } else {
            ans[n - i + inda[b[i]]]++;
            ma = max(ma, ans[n - i + inda[b[i]]]);
        }
    }

    cout << ma << '\n';
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
