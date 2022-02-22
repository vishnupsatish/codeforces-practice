#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    int l = 0, r = 0;
    ll ans = 0;

    int curq = 0;
    char prevq = 'a';

    while (l < n && r < n) {
        if (s[r] == '?') {
            curq++;
            ans += r - l + 1;
            r++;
        } else {
            if (curq & 1 && prevq != s[r] && prevq != 'a') { // Invalid
                l = r - curq;
                curq = 0;
                prevq = 'a';
            } else if (!(curq & 1) && prevq == s[r] && prevq != 'a') { // Invalid
                l = r - curq;
                curq = 0;
                prevq = 'a';
            } else if (s[r] == s[r + 1] && r < n - 1) { // Invalid
                ans += r - l + 1;
                l = ++r;
                curq = 0;
                prevq = s[r];
                continue;
            } else { // Valid
                curq = 0;
                prevq = s[r];
                ans += r - l + 1;
                r++;
            }
        }
    }

    cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}
