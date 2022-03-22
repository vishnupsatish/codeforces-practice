#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: binary search for the answer. Greedily move the maximum amount of stones
// starting from the rightmost heap. BUT we know that actually we are moving stones
// going from left to right, so we can only move h[i] stones (the original h[i])
// from the right. So, we should set d = min(h[i], h`[i] - x) / 3 for each i when
// binary searching the answer, where h`[i] is the new number of stones are the
// current heap.


void solve() {
    int n;
    cin >> n;

    vector<ll> h(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    auto check = [&](int val) -> bool {
        vector<ll> hp = h;
        for (int i = n; i >= 3; i--) {
            ll d = max(0ll, min(hp[i] - val, h[i])) / 3;
            hp[i - 1] += d;
            hp[i - 2] += 2 * d;
            hp[i] -= 3 * d;
        }

        for (int i = 1; i <= n; i++) {
            if (hp[i] < val) {
                return false;
            }
        }

        return true;
    };

    int l = 0, r = 1e9 + 1;

    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cout << l - 1 << '\n';
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
