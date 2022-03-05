#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Optimal idea: Give a1, a2, ... a(p - 1), then an to each person, sorted descending, 
// so the least numbers are not counted in the total sum, as greedily as possible (but 
// a1 must be). Sort people descending so the lower numbers are not counted with an 
// increasing degree, since we want to be greedy. I was so close to solving this myself!!


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    multiset<int, greater<>> w;

    ll ans = 0;

    sort(a.begin() + 1, a.begin() + n + 1);

    for (int i = 1; i <= k; i++) {
        int b; cin >> b;
        if (b == 1) {
            ans += (ll) a[n] * 2ll;
            n--;
        } else {
            w.emplace(b);
        }
    }

    int st = 1, en = n;

    for (auto b : w) {
        ans += (ll) a[st];
        st += b - 1;
        ans += (ll) a[en--];
    }

    cout << ans << '\n';
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
