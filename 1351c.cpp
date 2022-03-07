#include <bits/stdc++.h>

using namespace std;


void solve() {
    string s;
    cin >> s;
    
    set<tuple<int, int, int, int>> m; // Segments that have already been visited

    int x = 0, y = 0;

    int ans = 0;

    for (auto c : s) {
        int dx = x, dy = y;
        if (c == 'N') {
            dy++;
        } else if (c == 'S') {
            dy--;
        } else if (c == 'E') {
            dx++;
        } else {
            dx--;
        }

        if (m.contains(make_tuple(x, y, dx, dy)) || m.contains(make_tuple(dx, dy, x, y))) {
            ans++;
        } else {
            ans += 5;
            m.emplace(x, y, dx, dy);
        }

        x = dx;
        y = dy;
    }

    cout << ans << '\n';
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
