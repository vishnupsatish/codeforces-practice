#include <bits/stdc++.h>

using namespace std;

// When a and b differ by one this equation becomes valid

#define ll long long


void solve() {
    int n;
    cin >> n;

    int cnt = 5;
    int ans = 0;
    int dif = 8;

    while (cnt <= n) {
        ans++;
        cnt += dif;
        dif += 4;
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
