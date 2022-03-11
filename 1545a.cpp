#include <bits/stdc++.h>

using namespace std;

// Each number should move an even distance. Count number of even and
// odd in unsorted and sorted lists, for each number if the number of
// indices that are even/odd are not the same, it is a no.


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2), srt(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        srt[i] = a[i];
    }

    sort(srt.begin() + 1, srt.begin() + n + 1);

    unordered_map<int, int> nse, sse, nso, sso;

    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            sso[srt[i]]++;
            nso[a[i]]++;
        } else {
            sse[srt[i]]++;
            nse[a[i]]++;
        }
    }

    for (auto [k, v] : sse) {
        if (nse[k] != sse[k]) {
            cout << "NO" << '\n';
            return;
        }
    }

    for (auto [k, v] : sso) {
        if (nso[k] != sso[k]) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
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

