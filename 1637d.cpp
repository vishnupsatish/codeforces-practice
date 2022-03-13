#include <bits/stdc++.h>

using namespace std;

#define ll long long

// dp[i][j]: can a sum of j can be made using the first i elements?
// If so, how? (use bitset to store which ones were chosen). We do this
// since we want to minimize the sum of each array (similar to
// knapsack).


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2), b(n + 2);

    int as = 0, bs = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        as += a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        bs += b[i];
    }

    int avg = (bs + as) / 2;

    vector<vector<bitset<103>>> dp(n + 2, vector<bitset<103>>(100003));

    // Default value; if a sum does not exist
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 100003; j++) {
            dp[i][j][102] = 1;
        }
    }

    dp[1][a[1]][102] = 0;
    dp[1][a[1]][1] = 1;
    dp[1][b[1]][102] = 0;

    // Find closest sum to ts / 2
    for (int i = 2; i <= n; i++) {
        // Try a[i]
        for (int j = a[i]; j <= 100003; j++) {
            if (dp[i - 1][j - a[i]][102] == 0) { // Not a default value
                dp[i][j] = dp[i - 1][j - a[i]];
                dp[i][j][i] = 1;
            }
        }

        // Try b[i]
        for (int j = b[i]; j <= 100003; j++) {
            if (dp[i - 1][j - b[i]][102] == 0) { // Not a default value
                dp[i][j] = dp[i - 1][j - b[i]];
                dp[i][j][102] = 0; // Current one is not default anymore
            }
        }
    }

    int ob = avg, oa = avg + (avg & 1);
    bitset<103> cor;

    while (ob != 0 && oa != 100003) {
        if (dp[n][ob][102] == 0) {
            cor = dp[n][ob];
            break;
        }

        if (dp[n][oa][102] == 0) {
            cor = dp[n][oa];
            break;
        }

        ob--;
        oa++;
    }

    for (int i = 1; i <= n; i++) {
        if (cor[i] == 1) {
            swap(a[i], b[i]);
        }
    }

    int as_ = 0, bs_ = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            as_ += (a[i] + a[j]) * (a[i] + a[j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            bs_ += (b[i] + b[j]) * (b[i] + b[j]);
        }
    }

    cout << as_ + bs_ << '\n';
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




