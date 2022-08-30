/**
*  author:  vishnus
*  created: 2022-08-30
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: it is optimal to only ever perform operations of either length 1 or length 2. We can perform
// consecutive length-2 operations on subsegments whose xor is 0. Why? Let an operation be (a1, a2, x).
// First we make a[l] = 0 by doing (l, l + 1, a[l]). Then we make a[l + 1] = 0 by doing
// (l + 1, l + 2, a[l] ^ a[l + 1]). Then so on until the last element, where we do
// (r - 1, r, a[l] ^ ... ^ a[r - 1]). a[l] ^ ... ^ a[r - 1] is equal to a[r] because we know the xor
// of the entire subarray is 0. So, this means that the number of operations is one less than the size
// of the subarray. We can put prefix xors in a set and once a value is found to exist in the array,
// we just clear the set and keep going, and subtract one from answer (which is initially 'n').

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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i > 0) {
        a[i] ^= a[i - 1];
      }
    }
    unordered_set<int> cur = {0};
    int ans = n;
    for (auto px : a) {
      if (cur.contains(px)) {
        ans--;
        cur.clear();
      }
      cur.insert(px);
    }
    cout << ans << '\n';
  }
}
