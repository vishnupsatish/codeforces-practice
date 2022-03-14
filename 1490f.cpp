#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: brute-force all possibilities of a certain count (number of times
// a number occurs in the element) value. It will be O(sqrt(n)^2) which is O(n).


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2);

    unordered_map<int, int> oc;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        oc[a[i]]++;
    }

    unordered_map<int, int> cnt;

    for (auto [k, v] : oc) {
        cnt[v]++;
    }

    int ans = 1e9;

    for (auto [k, v] : cnt) { // Make everything have k occurrences
        int rm = 0;

        for (auto [nk, nv] : cnt) {
            if (nk < k) {
                rm += nv * nk;
            } else {
                rm += (nk - k) * nv;
            }
        }

        ans = min(ans, rm);
    }

    cout << ans << '\n';
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
