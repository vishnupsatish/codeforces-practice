#include <bits/stdc++.h>

using namespace std;

// Idea: use PSA and determine where (from the start) to combine and how to partition the rest of the elements

#define ll long long


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2), psa(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = a[i] + psa[i - 1];
    }

    int ans = n - 1;

    for (int i = 1; i <= n; i++) {
        int prv = psa[i], prind = i, cur = 0;

        bool ok = false;

        for (int j = i + 1; j <= n; j++) {
            if (psa[j] - psa[prind] == prv) {
                if (j == n) ok = true;
                prind = j;
                cur++;
            }
        }

        if (ok) {
            ans = min(ans, n - cur - 1);
        }
    }

    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) solve();
}
