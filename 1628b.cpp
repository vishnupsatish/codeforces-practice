#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: we can form a palindrome using only two strings. Store the indices of 
// each string where they appear. If an index of a palindrome-making string 
// appears after the current string's index, we have found an answer.


void solve() {
    int n;
    cin >> n;

    vector<string> a(n + 2);
    unordered_map<string, vector<int>> s;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[a[i]].emplace_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (a[i].size() == 1 || (a[i].size() == 2 && a[i][0] == a[i][1]) || (a[i].size() == 3 && a[i][0] == a[i][2])) {
            cout << "YES" << '\n';
            return;
        }
    }

    for (auto &[k, v] : s) {
        sort(v.begin(), v.end());
    }

    for (const auto &[e, ind] : s) {
        if (e.size() == 2) {
            string s1 = string(1, e[1]) + e[0];
            if (s.contains(s1) && s[s1][s[s1].size() - 1] > ind[0]) {
                cout << "YES" << '\n';
                return;
            }

            for (char c = 'a'; c <= 'z'; c++) {
                string s2 = string(1, c) + e[1] + e[0];
                if (s.contains(s2) && s[s2][s[s2].size() - 1] > ind[0]) {
                    cout << "YES" << '\n';
                    return;
                }
            }
        } else if (e.size() == 3) {
            string s1 = string(1, e[1]) + e[0];
            if (s.contains(s1) && s[s1][s[s1].size() - 1] > ind[0]) {
                cout << "YES" << '\n';
                return;
            }

            string s2 = string(1, e[2]) + e[1] + e[0];
            if (s.contains(s2) && s[s2][s[s2].size() - 1] > ind[0]) {
                cout << "YES" << '\n';
                return;
            }
        }
    }

    cout << "NO" << '\n';
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}
