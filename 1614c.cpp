    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define ll long long
     
    const int MOD = 1e9 + 7;
     
     
    void solve() {
        int n, m;
        cin >> n >> m;
     
        ll mx = 0;
     
        for (int i = 1; i <= m; i++) {
            int u1, u2;
            ll a;
            cin >> u1 >> u2 >> a;
            mx |= a;
        }
        
        mx %= MOD;
     
        ll ans = 1;
        for (int i = 1; i < n; i++) {
            ans *= 2;
            ans %= MOD;
        }
     
        cout << (ans * mx) % MOD << '\n';
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
    
