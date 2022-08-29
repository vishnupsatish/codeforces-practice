/**
*  author:  vishnus
*  created: 2022-08-29
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: loop final sum 'i'. The total answer for that is 2 * (number of elements where the range does not fall
// inside i), 1 * (the rest - those that already sum to 'i'). The "2 *" value can be precalculated using prefix sums.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    n /= 2;
    vector<int> a1(n), a2(n);
    for (int i = 0; i < n; i++) {
      cin >> a1[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> a2[i];
    }
    reverse(a2.begin(), a2.end());
    vector<int> maxp(2 * k + 2), minp(2 * k + 2);
    for (int i = 0; i < n; i++) {
      maxp[max(a1[i], a2[i]) + k]++;
      minp[min(a1[i], a2[i]) + 1]++;
    }
    for (int i = 1; i <= 2 * k; i++) {
      maxp[i] += maxp[i - 1];
    }
    for (int i = 2 * k - 1; i >= 0; i--) {
      minp[i] += minp[i + 1];
    }
    unordered_map<int, int> already_s;
    for (int i = 0; i < n; i++) {
      already_s[a1[i] + a2[i]]++;
    }
    int ans = 1e9;
    for (int i = 2; i <= 2 * k; i++) {
      ans = min(ans, maxp[i - 1] * 2 + minp[i + 1] * 2 + (n - (maxp[i - 1] + minp[i + 1]) - already_s[i]));
    }
    cout << ans << '\n';
  }
}
