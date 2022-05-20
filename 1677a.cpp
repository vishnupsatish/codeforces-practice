/**
 *    author:  vishnus
 *    created: 2022-05-20
**/
#include <bits/stdc++.h>

using namespace std;

// First step: calculate val[b]. val[b] = the number of indices d such that d > b that satisfy
// p[b] > p[d]. In the next loop, we loop c, then loop a, and we add to the answer all val from
// the range a + 1 to c - 1. But, this might include some false answers. This may include some
// values of d that are less than c. But, d must be greater than c! How can we fix this? Before
// adding to the answer, we imagine c to be d. Since c can only increase, we want to remove all
// occurrences from each b for which c (actually d) was an index. That way, val[b] for all b
// only counts the number of d such that d > c, not just d > b.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    vector<int> val(n); // Number of d that satisfies a[i] > a[d]
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (p[i] > p[j]) {
          val[i]++;
        }
      }
    }
    long long ans = 0;
    for (int c = 0; c < n; c++) {
      for (int b = 0; b < c; b++) {
        if (p[b] > p[c]) {
          val[b]--;
        }
      }
      vector<long long> pref(n + 1);
      for (int i = 0; i < c; i++) {
        pref[i + 1] = pref[i] + val[i];
      }
      for (int a = 0; a < c - 1; a++) {
        if (p[c] > p[a]) {
          ans += pref[c] - pref[a + 1];
        }
      }
    }
    cout << ans << '\n';
  }
}
