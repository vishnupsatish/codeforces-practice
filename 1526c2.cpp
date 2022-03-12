#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Keep adding, when you can't, if the least element is less than the current element,
// remove the least element and add the current element. Why does this work? We want to
// greedily add the greatest negative numbers that we can, and removing a lesser
// negative number to add a greater negative number will ensure that we are optimally
// choosing potions to drink. If a number doesn't work and is the most negative, we shouldn't
// remove >= 2 negatives to add it, since then we won't be drinking optimally.


void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 2);
    multiset<int> p;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll h = 0;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] + h >= 0) {
            h += a[i];
            ans++;
            p.emplace(a[i]);
        } else {
            if (!p.empty() && *p.begin() < a[i]) {
                h -= *p.begin();
                p.erase(p.begin());
                p.emplace(a[i]);
                h += a[i];
            }
        }
    }

    cout << ans << '\n';
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

