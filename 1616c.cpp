#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2);
    unordered_map<int, int> cn;
    int mxcn = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cn[a[i]]++;
        mxcn = max(cn[a[i]], mxcn);
    }

    int mx = mxcn;

    // Find longest arithmetic sequence
    for (int i = 1; i <= n; i++) {
        for (int sk = 1; sk + i <= n; sk++) {
            unordered_map<double, int> dif;
            int cnt = 0;
            for (int j = i + sk; j <= n; j += sk) {
                dif[(ld) (a[j] - a[i]) / ((ld) (j - i) / (ld) sk)]++;
                cnt = max(cnt, dif[(ld) (a[j] - a[i]) / ((ld) (j - i) / (ld) sk)]);
            }
            mx = max(mx, cnt + 1);
        }
    }

    cout << (n == 1 ? 0 : n - mx) << '\n';
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

