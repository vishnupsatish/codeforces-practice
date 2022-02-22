#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: add an edge from 1 to the node with the largest d[i] value.
// Then, add an edge from u -> v is d[v] <= d[u] with a weight of
// d[v] - d[u]. The shortest path to go from 1 to u will go from
// 1 -> node with largest d[i] value -> v. Every other edge will
// remain unused in the shortest path because an edge from u -> v
// must have an edge weight of >= d[v] - d[u] (otherwise, there will
// be a path from 1 to u with a total weight of less than the shortest
// path d[u]), but will contribute to the total answer.


void solve() {
    int n;
    cin >> n;

    vector<int> d(n + 2);

    for (int i = 1; i <= n; i++) cin >> d[i];

    sort(d.begin() + 1, d.begin() + n + 1);

    ll ans = d[n], cs = 0;

    for (int i = 1; i <= n; i++) {
        ans -= (ll) (i - 1) * (ll) d[i] - cs;
        cs += d[i];
    }

    cout << ans << '\n';
}


signed main() {
    int t; cin >> t;

    while (t--) solve();
}
