#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    set<int> a;

    for (int i = 1; i <= n; i++) {
        int b; cin >> b;
        a.emplace(b);
    }

    if (a.size() > k) {
        cout << -1 << '\n';
        return;
    }

    int cur = 1;

    while (k != a.size()) {
        while (a.contains(cur)) {
            cur++;
        }

        a.emplace(cur);
    }
    
    cout << n * a.size() << '\n';

    for (int i = 1; i <= n; i++) {
        for (auto e : a) {
            cout << e << ' ';
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
