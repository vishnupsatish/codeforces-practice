/**
 *    author:  vishnus
 *    created: 2022-07-10
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Idea: the next move does not depend on the end that we place the current number at.
// Therefore, the optimal strategy is to reduce the number of inversions at each step
// based on the number of elements that are greater than / less than the current number.

typedef tree<int, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) {
      cin >> e;
    }
    long long ans = 0;
    ordered_set vals;
    vals.insert(a[0]);
    unordered_map<int, int> cnt;
    cnt[a[0]]++;
    for (int i = 1; i < n; i++) {
      int lt = vals.order_of_key(a[i]);
      ans += min(lt, (int) vals.size() - lt - cnt[a[i]]);
      vals.insert(a[i]);
      cnt[a[i]]++;
    }
    cout << ans << '\n';
  }
}
