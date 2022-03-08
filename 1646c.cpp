#include <bits/stdc++.h>

using namespace std;

#define ll long long

// 14! and 2^39


void solve() {
    ll n;
    cin >> n;

    deque<ll> fact(16);
    fact[0] = 1;

    for (int i = 1; i <= 15; i++) {
        fact[i] = fact[i - 1] * (ll) i;
    }

    // Remove 0!, 1!, and 2! to avoid overcounting in powers of 2
    fact.pop_front();
    fact.pop_front();
    fact.pop_front();

    // x! is represented by fact[x - 3] now

    int k = 1e9;

    for (int i = 0; i < (1 << 13); i++) {
        string r = bitset<13>(i).to_string();
        reverse(r.begin(), r.end());

        ll su = 0;
        int cnt = 0;

        for (int j = 0; j < 13; j++) {
            if (r[j] == '1') {
                su += fact[j];
                cnt++;
            }
        }

        k = min(k, cnt + popcount((unsigned long long) (n - su)));
    }

    cout << k << '\n';
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
