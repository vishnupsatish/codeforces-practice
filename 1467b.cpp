/**
 *    author:  vishnus
 *    created: 2022-08-17
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: when you change a value, its value and its neighbours are the ones that are possibly 
// affected. What is the optimal value for a[i]? It is either a[i + 1] or a[i - 1]. Why? 
// Because it is guaranteed to remove two hills/valleys, a[i] and whichever element we are 
// setting it to. Other one may be removed.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) {
      cin >> e;
    }
    vector<int> h(n), v(n), any(n);
    int tot = 0;
    for (int i = 1; i < n - 1; i++) {
      h[i] = (a[i] > a[i - 1] && a[i] > a[i + 1]);
      v[i] = (a[i] < a[i - 1] && a[i] < a[i + 1]);
      tot += h[i] + v[i];
      any[i] = h[i] | v[i];
    }
    int red = 0;
    for (int i = 1; i < n - 1; i++) {
      // Change a[i] to either a[i - 1] or a[i + 1] and check.
      int old_val = a[i];
      a[i] = a[i - 1];
      int cur_tot = 0;
      if (i != 1) {
        cur_tot += (a[i - 1] > a[i - 2] && a[i - 1] > a[i]) || (a[i - 1] < a[i - 2] && a[i - 1] < a[i]);
      }
      if (i != n - 2) {
        cur_tot += (a[i + 1] > a[i + 2] && a[i + 1] > a[i]) || (a[i + 1] < a[i + 2] && a[i + 1] < a[i]);
      }
      cur_tot += (a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]);
      red = max(red, any[i] + any[i + 1] + any[i - 1] - cur_tot);
      a[i] = a[i + 1];
      cur_tot = 0;
      if (i != 1) {
        cur_tot += (a[i - 1] > a[i - 2] && a[i - 1] > a[i]) || (a[i - 1] < a[i - 2] && a[i - 1] < a[i]);
      }
      if (i != n - 2) {
        cur_tot += (a[i + 1] > a[i + 2] && a[i + 1] > a[i]) || (a[i + 1] < a[i + 2] && a[i + 1] < a[i]);
      }
      cur_tot += (a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]);
      red = max(red, any[i] + any[i + 1] + any[i - 1] - cur_tot);
      a[i] = old_val;
    }
    cout << tot - red << '\n';
  }
}
