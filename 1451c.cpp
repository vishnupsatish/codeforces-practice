#include <bits/stdc++.h>

using namespace std;

// Idea: if there are any characters in a that are greater than the greater b character, no.
// Swaps allow you to move around characters as you please. Set all same characters to one
// another, then, for each other remaining character in b, greedily give it to another
// character in a.


void solve() {
    int n, k;
    string a, b;

    cin >> n >> k >> a >> b;

    string sb = b;

    sort(begin(sb), end(sb));

    for (int i = 0; i < n; i++) {
        if (a[i] > sb[n - 1]) {
            cout << "No" << '\n';
            return;
        }
    }

    unordered_map<char, int> ca;

    for (int i = 0; i < n; i++) {
        ca[a[i]]++;
    }

    unordered_map<char, int> cb;

    for (int i = 0; i < n; i++) {
        cb[b[i]]++;
    }

    for (auto &[ke, v] : cb) {
        if (ca.contains(ke)) {
            int ov = v;
            v -= min(v, ca[ke]);
            ca[ke] -= min(ca[ke], ov);
        }
    }

    for (auto [ke, v] : ca) {
        if (v % k != 0) {
            cout << "No" << '\n';
            return;
        }
    }

    for (auto &[ke, v] : cb) {
        if (v != 0) {
            if (v % k != 0) {
                cout << "No" << '\n';
                return;
            }

            for (char i = ke; i >= 'a'; i--) {
                if (v == 0) {
                    break;
                }

                if (ca[i] != 0) {
                    int ov = v;
                    v -= min(v, ca[i]);
                    ca[i] -= min(ca[i], ov);
                }
            }

            if (v != 0) {
                cout << "No" << '\n';
                return;
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
