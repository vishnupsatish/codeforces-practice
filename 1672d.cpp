/**
 *    author:  vishnus
 *    created: 2022-05-26
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Think of it the reverse way. Try to convert array b to array a using a greedy solution.
// We know that if b[i] == b[i + 1] then b[i + 1] can be moved somewhere to the left of b[i], we
// just don't know where. This is where the two pointers comes in. Have two pointers, ap and bp,
// to represent the current index at a and b. If b[bp] == b[bp - 1] we can add b[bp] to a multiset
// in case we will need it to the left of bp. Decrement bp. If a[ap] == b[bp], then we're good and
// decrement both. If they're not equal, find a[ap] in the multiset since we need it now. If it's
// not there, no answer. Otherwise, remove it and decrement ap. When b[bp] == b[bp - 1] we don't
// decrement ap because the two elements from 'b' being equal implies that one of them needs to
// be placed before, therefore will be removed. If a[ap] and b[bp] are not equal (and there is 
// an element from the multiset) we don't decrement bp as well because we want to make a[ap] equal
// to it by adding a previous element found in b (and inserting it between).

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
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    multiset<int> vals;
    int ap = n - 1;
    int bp = n - 1;
    bool ans = true;
    while (ap >= 0 && bp >= 0) {
      if (bp > 0 && b[bp] == b[bp - 1]) {
        vals.insert(b[bp]);
        bp--;
      } else if (a[ap] == b[bp]) {
        ap--;
        bp--;
      } else {
        if (!vals.contains(a[ap])) {
          ans = false;
          break;
        }
        vals.erase(vals.find(a[ap]));
        ap--;
      }
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
}
