#include <bits/stdc++.h>

using namespace std;

// Try all letters as the max one, first determine how much a
// letter exceeds all other letter by for each word (and sort).
// Once this becomes negative, you can't add new words anymore.


void solve() {
    int n;
    cin >> n;

    vector<string> a(n + 2);
    vector<multiset<int, greater<>>> c(6);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        vector<int> ch(6);

        for (auto e : a[i]) {
            ch[e - 'a']++;
        }

        for (int j = 0; j < 5; j++) {
            c[j].emplace(ch[j] - (a[i].size() - ch[j]));
        }
    }

    int ans = 0;

    for (int i = 0; i < 5; i++) {
        int cnt = 0;
        int val = 0;
        for (auto e : c[i]) {
            cnt += e;
            val++;
            if (cnt <= 0) {
                ans = max(ans, val - 1);
                break;
            }
        }
        if (cnt > 0) {
            ans = max(ans, val);
        }
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

