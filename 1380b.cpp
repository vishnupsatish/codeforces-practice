#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    string st;
    cin >> st;

    int n = st.size();

    int r = 0, p = 0, s = 0;

    for (int i = 0; i < n; i++) {
        if (st[i] == 'R') {
            r++;
        } else if (st[i] == 'S') {
            s++;
        } else {
            p++;
        }
    }

    char ans;

    if (p >= s && p >= r) {
        ans = 'S';
    } else if (s >= p && s >= r) {
        ans = 'R';
    } else {
        ans = 'P';
    }

    for (int i = 1; i <= n; i++) {
        cout << ans;
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
