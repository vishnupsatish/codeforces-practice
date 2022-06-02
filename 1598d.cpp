/**
 *    author:  vishnus
 *    created: 2022-06-02
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: nC3 is the total number of combinations. We also know that a 'bad' combination
// will have three elements, two that share the same topic and two that share the same
// difficulty. These cannot be the same two, since no two problems have the same topic
// and difficulty. Therefore, there will be one problem that shares a topic with one
// and a difficulty with other. Therefore, we can loop each problem and subtract from
// the total answer the number of ways to choose two elements such that they share a
// topic with problem 'i' and a difficulty with problem 'i', Use a map to implement.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    long long ans = (long long) n * (n - 1ll) * (n - 2ll) / 6ll; // Total combinations
    unordered_map<int, int> cnta, cntb;
    for (int i = 0; i < n; i++) {
      cnta[a[i]]++;
      cntb[b[i]]++;
    }
    for (int i = 0; i < n; i++) { // Subtract from the total combinations the number of ways to combine the number of
      ans -= (long long) (cnta[a[i]] - 1) * (long long) (cntb[b[i]] - 1);
    }
    cout << ans << '\n';
  }
}
