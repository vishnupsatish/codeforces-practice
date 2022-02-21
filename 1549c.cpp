#include <bits/stdc++.h>

using namespace std;

// At the end of the process, no friendships will exist. If all of a noble's friends are weaker,
// the node can't be killed. A noble will only survive if all of its friends are weaker than it.
// Why? Imagine if a noble is stronger. All of the weaker ones will die. And that node will die too.


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> sa(n + 2), wk(n + 2);

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        sa[u]++;
        sa[v]++;
        wk[u] += (v < u);
        wk[v] += (u < v);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += (sa[i] == wk[i]);
    }

    int q;
    cin >> q;

    while (q--) {
        int qt; cin >> qt;

        if (qt == 1) {
            int u, v; cin >> u >> v;

            if (v < u) {
                if (sa[v] == wk[v]) ans--;
            } else {
                if (sa[u] == wk[u]) ans--;
            }

            sa[u]++;
            sa[v]++;
            wk[u] += (v < u);
            wk[v] += (u < v);

            if (v < u) {
                if (sa[v] == wk[v]) ans++;
            } else {
                if (sa[u] == wk[u]) ans++;
            }
        } else if (qt == 2) {
            int u, v; cin >> u >> v;

            if (v < u) {
                if (sa[v] == wk[v]) ans--;
            } else {
                if (sa[u] == wk[u]) ans--;
            }

            sa[u]--;
            sa[v]--;
            wk[u] -= (v < u);
            wk[v] -= (u < v);

            if (v < u) {
                if (sa[v] == wk[v]) ans++;
            } else {
                if (sa[u] == wk[u]) ans++;
            }
        } else {
            cout << ans << '\n';
        }
    }
}
