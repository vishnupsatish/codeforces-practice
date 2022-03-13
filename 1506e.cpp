#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n;
    cin >> n;

    vector<int> q(n + 2);
    set<int> mi;
    set<int, greater<>> ma;

    vector<int> mipp, mapp;

    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }

    for (int i = 1; i <= n; i++) {
        if (q[i] != q[i - 1]) {
            mipp.emplace_back(q[i]);
            mapp.emplace_back(q[i]);
            for (int j = q[i - 1] + 1; j < q[i]; j++) {
                mi.emplace(j);
                ma.emplace(j);
            }
        } else {
            mipp.emplace_back(*mi.begin());
            mapp.emplace_back(*ma.begin());
            mi.erase(*mi.begin());
            ma.erase(*ma.begin());
        }
    }

    for (auto e : mipp) {
        cout << e << ' ';
    }
    cout << '\n';

    for (auto e : mapp) {
        cout << e << ' ';
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
