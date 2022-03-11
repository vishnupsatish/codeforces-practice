#include <bits/stdc++.h>

using namespace std;

// Idea: maintain a variable that determines which person is the winner
// so far. If some i is superior to w, set w to i. In the end, check
// whether w is superior to everyone else. Only one person can ever win
// gold.


void solve() {
    int n;
    cin >> n;

    vector<vector<int>> a(n + 2, vector<int>(6));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> a[i][j];
        }
    }

    int w = 1;

    for (int i = 2; i <= n; i++) {
        int cnt = 0;

        for (int j = 1; j <= 5; j++) {
            if (a[i][j] > a[w][j]) {
                cnt++;
            }
        }

        if (cnt < 3) {
            w = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (w == i) {
            continue;
        }

        int cnt = 0;

        for (int j = 1; j <= 5; j++) {
            if (a[i][j] > a[w][j]) {
                cnt++;
            }
        }

        if (cnt < 3) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << w << '\n';
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

