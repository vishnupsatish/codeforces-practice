#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> b(n + 2), p(n + 2), ans(n + 2, -1), psa(n + 2); // idx maps the vertex to its place when sorted by distance
    int rt;

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (i == b[i]) {
            rt = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    if (p[1] != rt) {
        cout << -1 << '\n';
        return;
    }

    ans[rt] = 0;
    psa[rt] = 0;

    for (int i = 2; i <= n; i++) {
        if (ans[b[p[i]]] == -1) {
            cout << -1 << '\n';
            return;
        }

        ans[p[i]] = i - psa[b[p[i]]];
        psa[p[i]] = psa[b[p[i]]] + ans[p[i]];
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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

