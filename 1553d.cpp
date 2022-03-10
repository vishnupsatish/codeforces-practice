#include <bits/stdc++.h>

using namespace std;

// Idea: a backspace removes two characters, the one we typed, and the one
// we didn't type since we pressed backspace instead. We can arbitrary remove
// any prefix of the string, but we must remove suffixes in twos. So, start
// at the end and check if we can make the string by removing some amount
// of characters (successive removals must be multiples of two)


void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();

    if (n < m) {
        cout << "NO" << '\n';
        return;
    }

    int cnt = 0;

    int i = n - 1, j = m - 1;
    while (i >= 0) {
        if (s[i] == t[j]) {
            cnt++;
            i--;
            j--;

            if (cnt == m) {
                cout << "YES" << '\n';
                return;
            }
        } else {
            i -= 2;
        }
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

