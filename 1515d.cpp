#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: greedily add socks from the max one to the min one such that colour added had
// less socks in the place it was added; we want to get the same amount of each colour in each thing.


void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    unordered_map<int, int> ls, rs;
    for (int i = 1; i <= l; i++) {
        int c; cin >> c;
        ls[c]++;
    }

    for (int i = 1; i <= r; i++) {
        int c; cin >> c;
        rs[c]++;
    }

    // Make l always less than or equal to r
    if (l > r) {
        swap(ls, rs);
        swap(l, r);
    }

    multimap<int, int, greater<>> ca; // Holds amount difference from r to l, and the colour of the difference value
    for (auto [k, v] : rs) {
        if (!ls.contains(k)) {
            ca.emplace(v, k);
        } else if (ls[k] < v) {
            ca.emplace(v - ls[k], k);
        }
    }

    int ans = 0;

    // Keep adding a sock from the minimum one. Be greedy, so that the sock added has less in the min one than the max one.
    while (l < r) {
        ans++;

        auto cur = ca.begin();
        ls[cur->second]++;
        rs[cur->second]--;

        if (cur->first > 2) {
            ca.emplace(cur->first - 2, cur->second);
            ca.erase(cur);
        } else {
            ca.erase(cur);
        }

        l++;
        r--;
    }

    int cnt = 0;

    for (auto [k, v] : ls) {
        if (!rs.contains(k)) {
            rs[k] = 0;
        }
    }

    for (auto [k, v] : rs) {
        if (!ls.contains(k)) {
            ls[k] = 0;
        }
    }

    for (auto [k, v] : ls) {
        cnt += abs(v - rs[k]);
    }

    for (auto [k, v] : rs) {
        cnt += abs(v - ls[k]);
    }

    cout << ans + cnt / 4 << '\n';
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
