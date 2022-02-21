#include <bits/stdc++.h>

using namespace std;

// Idea: first assign all of the ones with more than or equal to k occurrences, 
// then assign everything else (doesn't matter how we assign them)


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 2), c(n + 2);

    unordered_map<int, vector<int>> cnt;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]].emplace_back(i);
    }

    vector<int> r;

    for (auto [ke, v] : cnt) {
        if (v.size() >= k) {
            for (int i = 0; i < k; i++) {
                c[v[i]] = i + 1;
            }
        } else {
            for (auto e : v) {
                r.emplace_back(e);
            }
        }
    }

    for (int i = 0; i < r.size() / k * k; i++) {
        c[r[i]] = i % k + 1;
    }

    for (int i = 1; i <= n; i++) cout << c[i] << ' ';
    cout << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}
