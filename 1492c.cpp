#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: find each subsequence greedily from the left and the right. Answer will
// always be a combination of the left and right values since we're being greedy.


void solve() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    vector<int> lm, rm;
    int lc = 0, rc = m - 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == t[lc]) {
            lm.emplace_back(i);
            lc++;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == t[rc]) {
            rm.emplace_back(i);
            rc--;
        }
    }

    reverse(rm.begin(), rm.end());

    int ans = 0;

    for (int i = 1; i < m; i++) {
        ans = max(ans, rm[i] - lm[i - 1]);
    }

    cout << ans << '\n';
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
