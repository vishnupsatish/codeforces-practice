#include <bits/stdc++.h>

using namespace std;

// Optimal idea: given an array with n (n > k) unique elements,
// let's divide it into two arrays that sum to the first array,
// one with k unique elements, the next with n - k + 1 unique
// elements. Don't divide it into two arrays that are as close
// as possible in terms of unique elements, that is not optimal,
// since we may get arrays where the number of unique elements is
// purely less than k, but we want to keep the number as close to k
// as possible, thereby making the number of arrays a minimum

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 2);

    unordered_set<int> cnt;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt.insert(a[i]);
    }

    if (k == 1 && cnt.size() != 1) {
        cout << -1 << '\n';
        return;
    }

    auto find = [&](auto find, int cur) -> int {
        if (cur <= k) {
            return 1;
        }

        return find(find, cur - k + 1) + find(find, k);
    };

    cout << find(find, cnt.size()) << '\n';
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
