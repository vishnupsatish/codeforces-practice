    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define ll long long
     
    unordered_map<int, bool> memo;
     
     
     
    void solve() {
        int n;
        cin >> n;
     
        auto play = [](auto play, int num) -> bool { // Returns 1 if the current player win
            if (memo.contains(num)) {
                return memo[num];
            }
     
            if (num == 1) {
                return memo[num] = false;
            }
     
            if (num & 1 || num == 2) {
                return memo[num] = true;
            }
     
            for (int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    int d1 = i, d2 = num / i;
     
                    if ((d1 & 1) && !play(play, d2)) {
                         return memo[num] = true;
                    }
     
                    if ((d2 & 1) && !play(play, d1)) {
                        return memo[num] = true;
                    }
                }
            }
     
            return memo[num] = false;
        };
     
        if (play(play, n)) {
            cout << "Ashishgup" << '\n';
        } else {
            cout << "FastestFinger" << '\n';
        }
    }
     
     
    signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
     
        int t = 1;
        cin >> t;
     
        while (t--) {
            solve();
        }
    }
