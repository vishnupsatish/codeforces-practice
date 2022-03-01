#include <bits/stdc++.h>

using namespace std;

// Idea: force the other player to only have odd; if we have an odd,
// then we must subtract one. Otherwise, if dividing by two results
// in an odd (or 2), then do so, forcing the player to only choose 1.
// If dividing by two does not result in an odd, subtract one, forcing
// the player into choosing 1, again.

#define ll long long


void solve() {
    ll n;
    cin >> n;

    ll ans = 0;

    auto play = [&](auto play, bool player, ll rem) -> void {
        if (rem == 0) {
            return;
        }

        if (rem & 1) {
            if (player) {
                ans++;
            }
            play(play, !player, rem - 1);
        } else {
            if (rem / 2 == 2 || (rem / 2) & 1) {
                if (player) {
                    ans += rem / 2;
                }
                play(play, !player, rem / 2);
            } else {
                if (player) {
                    ans++;
                }
                play(play, !player, rem - 1);
            }
        }
    };

    play(play, 1, n);

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
