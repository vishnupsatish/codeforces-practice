#include <bits/stdc++.h>

using namespace std;

// Idea: very simple PSA... determine all occurrences of a certain ratio using a map.


void solve() {
    int n;
    string s;
    cin >> n >> s;

    s = '0' + s;

    vector<int> k(n + 2), d(n + 2);

    map<pair<int, int>, int> val;

    for (int i = 1; i <= n; i++) {
        k[i] = k[i - 1] + (s[i] == 'K');
        d[i] = d[i - 1] + (s[i] == 'D');

        int tk = k[i], td = d[i];

        int g = gcd(tk, td);
        tk /= g;
        td /= g;
        val[{tk, td}]++;
        cout << val[{tk, td}] << ' ';
    }
    cout << '\n';
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

