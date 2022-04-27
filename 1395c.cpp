/**
 *    author:  vishnus
 *    created: 2022-04-27
**/
#include <bits/stdc++.h>

using namespace std;

// Loop all possibilities of the final answer. Then, loop all possibilities of c[i].
// We know that for all c[i], c[i] | answer must equal answer since there cannot be
// any extra bits present in c[i]. If we find a b[j] for the current a[i] such that
// (b[j] & a[i]) | answer == answer, then we can keep going. Otherwise, the current
// answer does not work.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < (1 << 9); i++) {
    bool done = true;
    for (auto e : a) {
      bool ok = false;
      for (auto f : b) {
        if ((i | (f & e)) == i) {
          ok = true;
          break;
        }
      }
      if (!ok) {
        done = false;
        break;
      }
    }
    if (done) {
      cout << i << '\n';
      break;
    }
  }
}
