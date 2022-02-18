#include <bits/stdc++.h>

using namespace std;

// Start at i = 1. If MEX(i, n) == MEX(i, j) for all j from i to n, break and set
// i to j + 1. MEX value can only increase, and the maximum MEX value will be the
// one at the end, and since we want the lexicographically greatest one, find the
// minimum j so more possibly can be found.

const int MAXN = 2e5 + 3;

void solve() {
    int n, a[MAXN], sm[MAXN];

    cin >> n;

    set<int> suf;

    suf.insert(0);

    for (int i = 1; i <= n; i++) {
        suf.insert(i);
        cin >> a[i];
    }

    for (int i = n; i >= 1; i--) {
        if (suf.contains(a[i])) suf.erase(a[i]);
        sm[i] = *suf.begin();
    }

    int ind = 1;

    vector<int> ans;

    while (ind <= n) {
        set<int> cur;
        int cm = 0; // Holds the current MEX value

        for (int i = ind; i <= n; i++) {
            cur.insert(a[i]);

            while (cur.contains(cm)) cm++; // Calculate MEX value

            if (cm == sm[ind]) {
                ans.emplace_back(sm[ind]);
                ind = i + 1;
                break;
            }
        }
    }

    cout << ans.size() << '\n';

    for (int i = 0; i < ans.size(); i++) cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
}


int main() {
    int t; cin >> t;

    while (t--) solve();
}
