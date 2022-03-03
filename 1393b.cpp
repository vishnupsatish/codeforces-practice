#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2);

    unordered_map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    multiset<int, greater<>> p;

    for (auto [k, v] : mp) {
        p.emplace(v);
    }


    int q;
    cin >> q;

    auto ok = [&]() -> bool {
        vector<int> all;

        auto it = p.begin();

        all.emplace_back(*it);

        if (!p.empty()) {
            if (all[0] >= 8) {
                return true;
            }
        }

        if (p.size() >= 2) {
            it++;
            all.emplace_back(*it);

            if (all[0] >= 4 && all[1] >= 4 || all[0] >= 6 && all[1] >= 2) {
                return true;
            }
        }

        if (p.size() >= 3) {
            it++;
            all.emplace_back(*it);

            if (all[0] >= 4 && all[1] >= 2 && all[2] >= 2) {
                return true;
            }
        }

        return false;
    };

    while (q--) {
        char op;
        int pls;
        cin >> op >> pls;

        if (op == '+') {
            if (mp.contains(pls)) {
                p.erase(p.find(mp[pls]));
            }

            mp[pls]++;
            p.emplace(mp[pls]);

            cout << (ok() ? "YES" : "NO") << '\n';
        } else {
            if (mp.contains(pls)) {
                p.erase(p.find(mp[pls]));
            }

            mp[pls]--;

            if (mp[pls] == 0) {
                mp.erase(pls);
            } else {
                p.emplace(mp[pls]);
            }

            cout << (ok() ? "YES" : "NO") << '\n';
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--) {
        solve();
    }
}
