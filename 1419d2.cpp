#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: Binary search to find the max ice spheres that can be bought.
// If x of the cheapest spheres need to be bought, x + 1 of the
// most expensive spheres must "pad" them. Check this.


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.begin() + n + 1);

    auto check = [&] (int val) -> bool { // Can we take the first 'val' ice spheres?
        if (val >= (n - val)) {
            return false;
        }

        int l = n - val;

        int cnt = 0;

        for (int i = 1; i <= val; i++) {
            cnt += (a[i] < a[l] && a[i] < a[++l]);
        }

        return cnt == val;
    };

    int l = 0, r = n / 2 - !(n & 1);

    while (l < r) {
        int mid = (l + r) / 2;

        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    l -= !check(l);

    cout << l << '\n';

    int rem = n - l;

    vector<int> cur(n + 2);

    cur[1] = a[rem++];

    int ind = 2;

    for (int i = 1; i <= l; i++) {
        cur[ind++] = a[i];
        cur[ind++] = a[rem++];
    }

    int cnt = 0;

    for (int i = 2; i < n; i++) {
        if (cur[i] != 0 && cur[i + 1] != 0) {
            cnt += (cur[i] < cur[i - 1] && cur[i] < cur[i + 1]);
        }
    }

    for (int i = l + 1; i < rem; i++) {
        if (ind > n) {
            break;
        }
        cur[ind++] = a[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << cur[i] << ' ';
    }
    cout << '\n';
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //    cin >> t;

    while (t--) {
        solve();
    }
}
