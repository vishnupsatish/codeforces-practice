#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n;
    cin >> n;

    auto ask = [&](int l, int r) -> int {
        cout << "? " << l << ' ' << r << endl;
        int cnt;
        cin >> cnt;
        return cnt;
    };

    vector<int> ans(n + 2), val(n + 2);

    for (int i = 2; i <= n; i++) {
        val[i] = ask(1, i);
        ans[i] = val[i] - val[i - 1];
    }

    int fst = val[n] - ask(2, n);

    ans[1] = fst;
    ans[2] -= ans[1];

    cout << "! ";

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    cout << endl;
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
