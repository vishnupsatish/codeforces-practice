#include <bits/stdc++.h>

using namespace std;

#define ll long long

// :pog: I just solved an 1800!!!!1


void solve() {
    int n, c;
    cin >> n >> c;

    vector<int> a, cont(c + 2);

    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        if (!cont[b]) {
            a.emplace_back(b);
            cont[b]++;
        }
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 1) {
            continue;
        }

        for (int j = a[i]; j <= c; j += a[i]) { // For each multiple of a[i], if the multiplying factor does not exist, check if the range exists. If it does, the answer is no
            if (!cont[j / a[i]]) { // Now determine if there exists an element in the range j -> j + a[i] - 1
                int p1 = lower_bound(a.begin() + i - 1, a.end(), j) - (a.begin() + i);
                int p2 = upper_bound(a.begin() + i - 1, a.end(), a[i] + j - 1) - (a.begin() + i);
                if (p1 != p2) {
                    cout << "No" << '\n';
                    return;
                }
            }
        }
    }

    cout << "Yes" << '\n';
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

