#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> acp(k + 2), ac(n + 2), a(n + 2);

    for (int i = 1; i <= k; i++) {
        cin >> acp[i];
    }

    int cnt = 1;
    for (int i = 1; i <= k; i++) {
        cin >> ac[acp[cnt++]];
    }

    // Track ACs left of current position and right of current position
    multiset<int> l, r;

    for (int i = 1; i <= n; i++) {
        if (ac[i]) {
            r.emplace(ac[i] + i - 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (ac[i]) {
            r.erase(r.find(ac[i] + i - 1));
            l.emplace(n - i + ac[i] - 1);
        }

        if (r.empty()) {
            cout << *l.begin() - (n - i) + 1 << ' ';
        } else if (l.empty()) {
            cout << *r.begin() - i + 1 << ' ';
        } else {
            cout << min(*r.begin() - i + 1, *l.begin() - (n - i) + 1) << ' ';
        }
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

