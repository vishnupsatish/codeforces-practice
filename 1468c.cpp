#include <bits/stdc++.h>

using namespace std;


void solve() {
    int q;
    cin >> q;

    auto ccmp = [](pair<int, int> a, pair<int, int> b) -> bool {
        if (a.first == b.first) return a.second < b.second;
        else return a.first > b.first;
    };

    set<pair<int, int>> ind; // Sorted by index
    set<pair<int, int>, decltype(ccmp)> lrg; // Sorted by most amount of money

    int cnt = 1;

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int v; cin >> v;

            ind.emplace(cnt, v);
            lrg.emplace(v, cnt);
            cnt++;
        } else if (t == 2) {
            cout << (*ind.begin()).first << ' ';
            lrg.erase({(*ind.begin()).second, (*ind.begin()).first});
            ind.erase(ind.begin());
        } else {
            cout << (*lrg.begin()).second << ' ';
            ind.erase({(*lrg.begin()).second, (*lrg.begin()).first});
            lrg.erase(lrg.begin());
        }
    }

    cout << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--) solve();
}
