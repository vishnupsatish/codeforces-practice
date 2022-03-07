#include <bits/stdc++.h>

using namespace std;


void solve(vector<int> &primes) {
    int n;
    cin >> n;

    vector<int> a(n + 2), ans(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, vector<int>> pr;

    for (int i = 1; i <= n; i++) {
        for (auto p : primes) {
            if (a[i] % p == 0) {
                pr[p].emplace_back(i);
            }
        }
    }
    
    int m = 0;
    unordered_set<int> done;

    for (auto [p, v] : pr) {
        bool cng = false;
        for (auto e : v) {
            if (!done.contains(e)) {
                if (!cng) {
                    m++;
                }
                cng = true;
                done.emplace(e);
                ans[e] = m;
            }
        }
    }

    cout << m << '\n';

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
}


int main() {
    vector<int> sieve(1003, 1);

    sieve[0] = sieve[1] = 0;

    for (int i = 2; i * i <= 1000; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= 1000; j += i) {
                sieve[j] = 0;
            }
        }
    }

    vector<int> primes;

    for (int i = 1; i <= 1000; i++) {
        if (sieve[i]) {
            primes.emplace_back(i);
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve(primes);
    }
}
