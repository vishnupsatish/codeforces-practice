#include <bits/stdc++.h>

using namespace std;

// Make the square parallel to the four sides. Use trigonometry to solve.

#define ll long long
#define ld long double

const ld PI = 3.14159265358979323846264;


void solve() {
    ld n;
    cin >> n;
    n *= 2;

    ld angle = 180.0 / n;

    cout << fixed << setprecision(7) << 0.5 / tan(PI / 180.0 * angle) * 2 << '\n';
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
