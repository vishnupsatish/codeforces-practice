#include <bits/stdc++.h>

using namespace std;

// Why? The second-last/second-first strings are the most important. abcde -> abcded -> edcbabcded -> dedcbabcded

#define ll long long


void solve() {
    string tmp;
    cin >> tmp;

    int n = tmp.size();

    cout << 3 << '\n';

    cout << "R " << n - 1 << '\n';
    cout << "L " << n << '\n';
    cout << "L " << 2 << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--) {
        solve();
    }
}
