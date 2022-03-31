/**
 *    author:  vishnus
 *    created: 2022-03-30
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Greedy. Basically the question is asking can you take (r - l + 1) unique
// elements from 1 -> n and sum it to s. Greedily add elements if it possible to
// make a sum with the rest of the elements and the remaining sum. (i.e. the current
// element is not too low).

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int ps = s;
    int len = r - l + 1;
    auto RangeSum = [](int l, int r) { // find the sum of the range l -> r (inclusive) in a permutation of size n
      return (r * (r + 1) / 2) - ((l - 1) * l / 2);
    };
    int mx = RangeSum(n - len + 1, n);
    int mi = RangeSum(1, len);
    if (s < mi || s > mx) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> ans;
    unordered_set<int> nr;
    for (int i = 1; i <= n; i++) {
      nr.insert(i);
    }
    for (int i = 1; i <= n; i++) {
      s -= i;
      len--;
      int cmx = RangeSum(n - len + 1, n);
      if (s <= cmx) {
        ans.push_back(i);
        nr.erase(i);
      } else {
        s += i;
        len++;
      }
    }
    #ifdef LOCAL
    assert((int) ans.size() == (r - l + 1));
    int cs = 0;
    for (auto &e : ans) {
      cs += e;
    }
    assert(cs == ps);
    #endif
    for (int i = 1; i <= n; i++) {
      if (i > 1) {
        cout << ' ';
      }
      if (i >= l && i <= r) {
        cout << ans[(int) ans.size() - 1];
        ans.pop_back();
      } else {
        cout << *nr.begin();
        nr.erase(nr.begin());
      }
    }
    cout << '\n';
  }
}
