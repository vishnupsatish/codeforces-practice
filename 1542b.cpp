#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Idea: a number can be made up to n if the (n - number) % b == 0. Check all powers
// of a to find "a number". Why does this work? Imagine this case: 62172, a = 157,
// b = 239. This is (157+239)*157 = 157*157 + 239*157 and can be thought of doing
// 157^2 then adding 157 239s.


void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    if (a == 1) {
        if ((n - 1) % b == 0) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
        return;
    }

    if (n % b == 1) {
        cout << "Yes" << '\n';
        return;
    }

    ll ca = 1;

    while (true) {
        if (n % b == ca % b || n == ca) {
            cout << "Yes" << '\n';
            return;
        }
        ca *= a;
        if (ca > n) {
            cout << "No" << '\n';
            return;
        }
    }
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

