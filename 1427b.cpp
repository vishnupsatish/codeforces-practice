#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n, k;

    cin >> n >> k;

    int on = n;

    n += 2;

    int ogk = k;

    vector<int> a(n + 2);

    int cnt2 = 0;

    for (int i = 2; i < n; i++) {
        char c; cin >> c;
        a[i] = c == 'W' ? 1 : 0;
        cnt2 += a[i];
    }

    int cnt = a[1];
    int before = !a[1];
    int after = 0;

    vector<int> w; // Count, before

    bool fdone = false;

    int cnt1 = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            cnt++;
            after = 0;
        } else {
            if (cnt) {
                cnt1++;
                if (!fdone) {
                    fdone = true;
                } else {
                    w.emplace_back(before);
                }
                before = 0;
                cnt = 0;
            }
            before++;
            after++;
        }
    }

    if (cnt) {
        cnt1++;
        w.emplace_back(before);
        fdone = true;
    }

    sort(w.begin(), w.end());

    for (auto b : w) {
        if (b <= k) {
            k -= b;
            cnt1--;
        }
    }

    cnt2 = min(on, cnt2 + ogk);

    cnt1 += (!fdone);

    cout << max(0, 2 * cnt2 - cnt1) << '\n';
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
