#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, k;
    string s;

    unordered_map<char, int> cnt;

    cin >> n >> k >> s;

    for (auto c : s) cnt[c]++;

    int twos = 0, odd = 0;

    for (auto [c, v] : cnt) {
        odd += v & 1;
        twos += v / 2;
    }

    // There are some number of extra pairs that must be separated
    // and used as odd numbers. Once we've used some multiple of k
    // pairs, there will be some remaining. Put them in the middle
    odd += (twos % k) * 2;

    cout << (twos / k) * 2 + (odd >= k) << '\n';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}
