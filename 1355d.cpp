#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n, s;
    cin >> n >> s;

    if (s >= n * 2) {
        cout << "YES" << '\n';

        int cnt = 0;

        for (int i = 1; i < n; i++) {
            cnt += 2;
            cout << 2 << ' ';
        }

        cout << s - cnt << '\n';
        cout << 1 << '\n';
    } else {
        cout << "NO" << '\n';
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
