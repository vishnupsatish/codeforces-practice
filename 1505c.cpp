#include <bits/stdc++.h>

using namespace std;


void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> fib(n + 2);

    fib[0] = s[0] - 'A';
    fib[1] = s[1] - 'A';

    for (int i = 2; i < n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 26;
        if (fib[i] != s[i] - 'A') {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--) solve();
}
