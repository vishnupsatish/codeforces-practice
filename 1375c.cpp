#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    if (a[1] < a[n]) {
        cout << "YES" << '\n';
        return;
    }

    cout << "NO" << '\n';
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
